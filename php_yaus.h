#ifndef PHP_YAUS_H
#define PHP_YAUS_H 1

#define PHP_YAUS_VERSION "0.2.1"
#define PHP_YAUS_EXTNAME "YAUS"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

extern "C" {
#include "php.h"
}

PHP_MINIT_FUNCTION(yaus);
PHP_FUNCTION(stemword_ru);
PHP_FUNCTION(stemword_en);
PHP_FUNCTION(stemword_enru);

extern zend_module_entry yaus_module_entry;
#define phpext_yaus_ptr &yaus_module_entry

#endif
