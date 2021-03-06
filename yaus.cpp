#include "php_yaus.h"
#include "libsphinx/src/sphinxstem.h"
#include "libsphinx/libstemmer_c/include/libstemmer.h"

/* list entry identifier for snowball stemmer resource */
int le_yaus_snowball_stemmer;

zend_function_entry yaus_functions[] = {
    PHP_FE(stemword_ru, NULL)
    PHP_FE(stemword_en, NULL)
    PHP_FE(stemword_enru, NULL)
    PHP_FE(stemword_soundex, NULL)
    PHP_FE(stemword_dmetaphone, NULL)
    PHP_FE(stemword_snowball_new, NULL)
    PHP_FE(stemword_snowball_stem, NULL)
    PHP_FE(stemword_snowball_algorithm_list, NULL)
    PHP_FE(stemword_snowball_delete, NULL)
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
    PHP_MINFO(yaus),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_YAUS_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

PHP_MINIT_FUNCTION(yaus)
{
	stem_ru_init();
	stem_en_init();
	le_yaus_snowball_stemmer = zend_register_list_destructors_ex(php_yaus_snowball_stemmer_dtor, NULL, PHP_YAUS_SHOWBALL_STEMMER_RES_NAME, module_number);
	return SUCCESS;
}

PHP_MINFO_FUNCTION(yaus)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Version", PHP_YAUS_VERSION);
	php_info_print_table_header(2, "Compiled", __DATE__ " @ "  __TIME__);
	php_info_print_table_header(2, "libsphinx version", SPHINX_VERSION);
	php_info_print_table_end();
}

#ifdef COMPILE_DL_YAUS
extern "C" {
ZEND_GET_MODULE(yaus)
}
#endif


char *yaus_estrndup_with_padding(const char *s, size_t length)
{
	char *p;

	p = (char *)emalloc(length + YAUS_STRING_SAFETY_GAP + 1);
	if (UNEXPECTED(p == NULL)) {
		return p;
	}
	memcpy(p, s, length);
	memset(p + length, 0, YAUS_STRING_SAFETY_GAP + 1);
	return p;
}

void php_yaus_delete_snowball_stemmer_res(php_yaus_snowball_stemmer *stemmer_resource)
{
	if (stemmer_resource) {
		if (stemmer_resource->stemmer) {
			sb_stemmer_delete(stemmer_resource->stemmer);
            stemmer_resource->stemmer = NULL;
		}
		efree(stemmer_resource);
        stemmer_resource = NULL;
	}
}

PHP_FUNCTION(stemword_ru)
{
	char *word;
	char *result;
	size_t wordlen;
	zend_string *result_str;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = yaus_estrndup_with_padding(word, wordlen);

	stem_ru_utf8((WORD *)result);

	result_str = zend_string_init(result, strlen(result), 0);
	efree(result);
	RETURN_STR(result_str);
}

PHP_FUNCTION(stemword_en)
{
	char *word;
	char *result;
	size_t wordlen;
	zend_string *result_str;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = estrndup(word, wordlen);

	stem_en((BYTE *)result, wordlen);

	result_str = zend_string_init(result, strlen(result), 0);
	efree(result);
	RETURN_STR(result_str);
}

PHP_FUNCTION(stemword_enru)
{
	char *word;
	char *result;
	size_t wordlen;
	zend_string *result_str;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = yaus_estrndup_with_padding(word, wordlen);

	//Theoretically, the order of stemming is irrelevant.
	stem_en((BYTE *)result, wordlen);
	stem_ru_utf8((WORD *)result);

	result_str = zend_string_init(result, strlen(result), 0);
	efree(result);
	RETURN_STR(result_str);
}

PHP_FUNCTION(stemword_soundex)
{
	char *word;
	char *result;
	size_t wordlen;
	zend_string *result_str;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = estrdup(word);

	stem_soundex((BYTE *)result);

	result_str = zend_string_init(result, strlen(result), 0);
	efree(result);
	RETURN_STR(result_str);
}

PHP_FUNCTION(stemword_dmetaphone)
{
	char *word;
	char *result;
	size_t wordlen;
	zend_string *result_str;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &word, &wordlen) == FAILURE) {
		RETURN_NULL();
	}
	//We need to get a copy of input parameters, because stem functions
	//are destructive.
	result = estrdup(word);

	stem_dmetaphone((BYTE *)result);

	result_str = zend_string_init(result, strlen(result), 0);
	efree(result);
	RETURN_STR(result_str);
}

PHP_FUNCTION(stemword_snowball_new)
{
	php_yaus_snowball_stemmer *stemmer_resource;
	char *algorithm;
	size_t algorithm_len;
	char *charenc = NULL;
	size_t charenc_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s", &algorithm, &algorithm_len, &charenc, &charenc_len) == FAILURE) {
		RETURN_FALSE;
	}

	stemmer_resource = static_cast<php_yaus_snowball_stemmer *>(emalloc(sizeof(php_yaus_snowball_stemmer)));
	stemmer_resource->stemmer = sb_stemmer_new(algorithm, charenc);
	if (!stemmer_resource->stemmer) {
		efree(stemmer_resource);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not create stemmer with %s algorithm for %s charset", algorithm, charenc);
		RETURN_FALSE;
	}

	RETURN_RES(zend_register_resource(stemmer_resource, le_yaus_snowball_stemmer));
}

PHP_FUNCTION(stemword_snowball_stem)
{
	php_yaus_snowball_stemmer *stemmer_resource;
	zval *stemmer_resource_zval;
	char *word;
	size_t word_len;
	const sb_symbol *result;
	int result_len;
	zend_string *result_str;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rs", &stemmer_resource_zval, &word, &word_len) == FAILURE) {
		RETURN_FALSE;
	}

	if ((stemmer_resource = (php_yaus_snowball_stemmer *)zend_fetch_resource(Z_RES_P(stemmer_resource_zval), PHP_YAUS_SHOWBALL_STEMMER_RES_NAME, le_yaus_snowball_stemmer)) == NULL) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not fetch stemmer resource");
		RETURN_FALSE;
	}

	if (!stemmer_resource->stemmer) {
		efree(stemmer_resource);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Lost reference to a stemmer");
		RETURN_FALSE;
	}

	result = sb_stemmer_stem(stemmer_resource->stemmer, reinterpret_cast<const sb_symbol *>(word), word_len);
	result_len = sb_stemmer_length(stemmer_resource->stemmer);

	result_str = zend_string_init(reinterpret_cast<const char *>(result), result_len, 1);

	RETURN_STR(result_str);
}

PHP_FUNCTION(stemword_snowball_algorithm_list)
{
	int i = 0;
	const char **algo_list;

	algo_list = sb_stemmer_list();
	array_init(return_value);

	while (algo_list[i]) {
		add_next_index_string(return_value, algo_list[i]);
		i++;
	}
}

PHP_FUNCTION(stemword_snowball_delete)
{
	zval *stemmer_resource_zval;
	php_yaus_snowball_stemmer *stemmer_resource;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &stemmer_resource_zval) == FAILURE) {
		RETURN_FALSE;
	}

	stemmer_resource = (php_yaus_snowball_stemmer *) zend_fetch_resource(Z_RES_P(stemmer_resource_zval), PHP_YAUS_SHOWBALL_STEMMER_RES_NAME, le_yaus_snowball_stemmer);
	if (!stemmer_resource) {
		RETURN_FALSE;
	}

	zend_list_close(Z_RES_P(stemmer_resource_zval));
	RETURN_TRUE;
}

static void php_yaus_snowball_stemmer_dtor(zend_resource *rsrc TSRMLS_DC)
{
	php_yaus_delete_snowball_stemmer_res((php_yaus_snowball_stemmer *) rsrc->ptr);
}
