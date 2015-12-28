#ifndef PHP_YAUS_H
#define PHP_YAUS_H 1

#define PHP_YAUS_VERSION "0.4.0"
#define PHP_YAUS_EXTNAME "YAUS"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

extern "C" {
#include "php.h"
#include "ext/standard/info.h"
}

#include "libsphinx/libstemmer_c/include/libstemmer.h"

typedef struct _php_yaus_snowball_stemmer {
	struct sb_stemmer *stemmer;
} php_yaus_snowball_stemmer;

#define PHP_YAUS_SHOWBALL_STEMMER_RES_NAME "Snowball stemmer"

/* this is a copy-and-paste from sphinxstd.h */
/// safety gap after the string end; for instance, UTF-8 Russian stemmer
/// which treats strings as 16-bit word sequences needs this in some cases.
/// note that this zero-filled gap does NOT include trailing C-string zero,
/// and does NOT affect strlen() as well.
#define YAUS_STRING_SAFETY_GAP 4

char *yaus_estrndup_with_padding(const char *s, size_t length);
void php_yaus_delete_snowball_stemmer_res(php_yaus_snowball_stemmer *stemmer_resource);

PHP_MINIT_FUNCTION(yaus);
PHP_MINFO_FUNCTION(yaus);
PHP_FUNCTION(stemword_ru);
PHP_FUNCTION(stemword_en);
PHP_FUNCTION(stemword_enru);
PHP_FUNCTION(stemword_soundex);
PHP_FUNCTION(stemword_dmetaphone);
PHP_FUNCTION(stemword_snowball_new);
PHP_FUNCTION(stemword_snowball_stem);
PHP_FUNCTION(stemword_snowball_algorithm_list);
PHP_FUNCTION(stemword_snowball_delete);

static void php_yaus_snowball_stemmer_dtor(zend_resource *rsrc TSRMLS_DC);

extern zend_module_entry yaus_module_entry;
#define phpext_yaus_ptr &yaus_module_entry

#endif
