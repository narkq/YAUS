#include "php_yaus.h"
#include "sphinxstem.h"

static function_entry yaus_functions[] = {
    PHP_FE(stemword_ru_cp1251, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry yaus_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_YAUS_EXTNAME,
    yaus_functions,
    PHP_MINIT(yaus),
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_YAUS_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

PHP_MINIT_FUNCTION(yaus)
{
	stem_ru_init();
	return SUCCESS;
}

#ifdef COMPILE_DL_YAUS
extern "C" {
ZEND_GET_MODULE(yaus)
}
#endif

#define PHP_STEM_DEBUG 0

PHP_FUNCTION(stemword_ru_cp1251)
{
#if PHP_STEM_DEBUG
	const char* fmt = "\t%d";
#endif
	//static bool init = true;
	char *word, *out_word;
	BYTE* sph_word;
	int wordlen, i, stemlen = 0;
	bool stem_complete = false;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	sph_word = (BYTE*) emalloc(sizeof(BYTE) * (wordlen + 1));
	out_word = estrdup(word);
#if PHP_STEM_DEBUG
	php_printf("BEFORE\nword: %s\n", word);
	php_printf("signed charcodes: ");
#endif
	for (i = 0; i < wordlen; i++)
	{
#if PHP_STEM_DEBUG
		php_printf(fmt, word[i]);
#endif
		sph_word[i] = (BYTE)word[i];
	}
	sph_word[wordlen] = 0;
#if PHP_STEM_DEBUG
	php_printf("\nunsigned charcodes: ");
	for (i = 0; i < wordlen; i++)
	{
		php_printf(fmt, sph_word[i]);
	}
#endif
	stem_ru_cp1251(sph_word);
#if PHP_STEM_DEBUG
	php_printf("\nAFTER\nunsigned charcodes: ");
#endif
	for (i = 0; i < wordlen; i++)
	{
#if PHP_STEM_DEBUG
		php_printf(fmt, sph_word[i]);
#endif
		if (sph_word[i] == 0)
			stem_complete = true;
		if (stem_complete)
			out_word[i] = 0;
		else
		{
			out_word[i] = (char)sph_word[i];
			stemlen++;
		}
	}
	efree(sph_word);
#if PHP_STEM_DEBUG
	php_printf("\nsigned charcodes: ");
	for (i = 0; i < wordlen; i++)
		php_printf(fmt, out_word[i]);
	php_printf("\nword after: ");
	php_printf("%s\n", word);
#endif
	Z_TYPE_P(return_value) = IS_STRING;
	Z_STRVAL_P(return_value) = estrdup(out_word);
	Z_STRLEN_P(return_value) = stemlen;
	efree(out_word);
#if PHP_STEM_DEBUG
	php_printf("%s\t%d\n", return_value->value.str.val, return_value->value.str.len);
#endif
}
