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


PHP_MINIT_FUNCTION(hello_world)
{
	return SUCCESS;
}


PHP_MSHUTDOWN_FUNCTION(hello_world)
{
	return SUCCESS;
}



PHP_RINIT_FUNCTION(hello_world)
{
#if defined(COMPILE_DL_HELLO_WORLD) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}



PHP_RSHUTDOWN_FUNCTION(hello_world)
{
	return SUCCESS;
}


PHP_MINFO_FUNCTION(hello_world)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hello_world support", "enabled");
	php_info_print_table_end();

}


PHP_FUNCTION(say_hello_world)
{
	RETURN_STRING("Hello, World");
}


const zend_function_entry hello_world_functions[] = {
	PHP_FE(say_hello_world, NULL)
	PHP_FE_END
};


zend_module_entry hello_world_module_entry = {
	STANDARD_MODULE_HEADER,
	"hello_world",
	hello_world_functions,
	PHP_MINIT(hello_world),
	PHP_MSHUTDOWN(hello_world),
	PHP_RINIT(hello_world),	
	PHP_RSHUTDOWN(hello_world),
	PHP_MINFO(hello_world),
	PHP_HELLO_WORLD_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_HELLO_WORLD
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(hello_world)
#endif

