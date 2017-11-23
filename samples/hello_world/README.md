# Hello World

This is a very minimal hello world extension. It introduces the basic concepts around extension writing.

----

Please ensure all required packages and php-src is prepared. Refer to e[xtension dependencies](./../../README.md#installing-required-packages) for more details.

## Preamble
Traditionally, a minimal `Hello World` function in PHP could be:
```php
<?php

function hello_world()
{
	return "Hey, hello world";
}

echo hello_world();
```

To replicate the same as a PHP Extension can will be:\
```c
// ... some PHP-C related incantations

ZEND_FUNCTION(hello_world)
{
	RETURN_STRING("Hey, hello world");
}

// ... some other possible C incantations
```

And all we'll have to do in PHP is simply
```php
<?php

echo hello_world();
```

## Sample Code
In this sample **Hello World** extension code, there are some important files that help in making this work
File | Remark
---- | --------
config.m4 | Build configration file. In short
config.w32 | Windows equivalent build script
hello_world.c | Main extension source file
hello_world.php | Optional sample PHP script. Seriously, this is not the test!
funky.c | Optional additional source file
php_hello_world.h | Primary extension header file
tests/ | This is where extension tests live \`.phpt´