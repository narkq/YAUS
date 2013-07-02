#include "php_yaus.h"
#include "libsphinx/src/sphinxstem.h"

static function_entry yaus_functions[] = {
    PHP_FE(stemword_ru, NULL)
    PHP_FE(stemword_en, NULL)
    PHP_FE(stemword_enru, NULL)
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
	stem_en_init();
	return SUCCESS;
}

#ifdef COMPILE_DL_YAUS
extern "C" {
ZEND_GET_MODULE(yaus)
}
#endif


PHP_FUNCTION(stemword_ru)
{
	char *word;
	char *result;
	int wordlen;
	int is_utf = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|b", &word, &wordlen, &is_utf) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = estrdup(word);

	if (!is_utf)
	{
		stem_ru_cp1251((BYTE *)result);
	}
	else
	{
		stem_ru_utf8((WORD *)result);
	}

	Z_TYPE_P(return_value) = IS_STRING;
	Z_STRVAL_P(return_value) = estrdup(result);
	Z_STRLEN_P(return_value) = strlen(result);
	efree(result);
}

PHP_FUNCTION(stemword_en)
{
	char *word;
	char *result;
	int wordlen;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = estrdup(word);

	stem_en((BYTE *)result, wordlen);
        
	Z_TYPE_P(return_value) = IS_STRING;
	Z_STRVAL_P(return_value) = estrdup(result);
	Z_STRLEN_P(return_value) = strlen(result);
	efree(result);
}

PHP_FUNCTION(stemword_enru)
{
	char *word;
	char *result;
	int wordlen;
	int is_utf = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|b", &word, &wordlen, &is_utf) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = estrdup(word);

	//Theoretically, the order of stemming is irrelevant.
	stem_en((BYTE *)result, wordlen);
	if (!is_utf)
	{
		stem_ru_cp1251((BYTE *)result);
	}
	else
	{
		stem_ru_utf8((WORD *)result);
	}
        
	Z_TYPE_P(return_value) = IS_STRING;
	Z_STRVAL_P(return_value) = estrdup(result);
	Z_STRLEN_P(return_value) = strlen(result);
	efree(result);
}
