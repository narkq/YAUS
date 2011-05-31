PHP_ARG_ENABLE(yaus,
	[whether to enable YAUS support],
	[ --enable-yaus   Enable YAUS support])

if test "$PHP_YAUS" = "yes"; then
  AC_DEFINE(HAVE_YAUS, 1, [Whether you have YAUS])
  PHP_REQUIRE_CXX()
  PHP_SUBST(YAUS_SHARED_LIBADD)
  PHP_ADD_LIBRARY(stdc++, 1, YAUS_SHARED_LIBADD)
  PHP_NEW_EXTENSION(yaus, yaus.cc sphinxstemru.cpp, $ext_shared)
fi
