PHP_ARG_ENABLE(hello,
	[whether to enable Hello World support],
	[ --enable-hello   Enable Hello World support])

if test "$PHP_HELLO" = "yes"; then
  AC_DEFINE(HAVE_HELLO, 1, [Whether you have Hello World])
  PHP_REQUIRE_CXX()
  PHP_SUBST(HELLO_SHARED_LIBADD)
  PHP_ADD_LIBRARY(stdc++, 1, VEHICLES_SHARED_LIBADD)
  PHP_NEW_EXTENSION(hello, hello.cc sphinxstemru.cpp, $ext_shared)
fi
