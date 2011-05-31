#ifndef PHP_YAUS_H
#define PHP_YAUS_H 1

#define PHP_YAUS_VERSION "1.0"
#define PHP_YAUS_EXTNAME "hello"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

extern "C" {
#include "php.h"
}

PHP_MINIT_FUNCTION(yaus);
PHP_FUNCTION(stemword_ru_cp1251);

extern zend_module_entry yaus_module_entry;
#define phpext_yaus_ptr &yaus_module_entry

#endif
