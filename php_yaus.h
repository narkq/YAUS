#ifndef PHP_YAUS_H
#define PHP_YAUS_H 1

#define PHP_YAUS_VERSION "0.2.1"
#define PHP_YAUS_EXTNAME "YAUS"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

extern "C" {
#include "php.h"
#include "ext/standard/info.h"
}

#include "libstemmer.h"

typedef struct _php_yaus_snowball_stemmer {
	struct sb_stemmer *stemmer;
} php_yaus_snowball_stemmer;

#define PHP_YAUS_SHOWBALL_STEMMER_RES_NAME "Snowball stemmer"

PHP_MINIT_FUNCTION(yaus);
PHP_MINFO_FUNCTION(yaus);
PHP_FUNCTION(stemword_ru);
PHP_FUNCTION(stemword_en);
PHP_FUNCTION(stemword_enru);
PHP_FUNCTION(stemword_soundex);
PHP_FUNCTION(stemword_dmetaphone);
PHP_FUNCTION(stemword_snowball_new);
PHP_FUNCTION(stemword_snowball_stem);
PHP_FUNCTION(stemword_snowball_delete);

static void php_yaus_snowball_stemmer_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC);

extern zend_module_entry yaus_module_entry;
#define phpext_yaus_ptr &yaus_module_entry

#endif
