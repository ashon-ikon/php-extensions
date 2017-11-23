PHP_ARG_ENABLE(hello_world, whether to enable hello_world support,
dnl Make sure that the comment is aligned:
[  --enable-hello_world           Enable hello_world support])

if test "$PHP_HELLO_WORLD" != "no"; then

  PHP_NEW_EXTENSION(hello_world, funky.c hello_world.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
