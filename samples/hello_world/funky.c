/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:  Yinka Asonibare                                             |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_hello_world.h"

ZEND_FUNCTION(say_zahp)
{
    char *za_name;
    size_t za_name_len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &za_name, &za_name_len) == FAILURE) {
      return;
    }

    const char *straya_lingos[] = {
      "ie",
      "ish",
      "na"
    };

    char *name = emalloc((za_name_len + 5 + 1) * sizeof name); // Assumes no lingo longer than 4 chars
    if (!name) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed to allocate memory");
        RETURN_NULL();
    }

    php_sprintf(name, "Yo! %s'%s", za_name, straya_lingos[rand() % 3]);

    RETVAL_STRING(name);
    efree(name);
}