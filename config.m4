PHP_ARG_ENABLE(yaus,
	[whether to enable YAUS support],
	[ --enable-yaus   Enable YAUS support])

if test "$PHP_YAUS" = "yes"; then
	# check endianness
	AC_C_BIGENDIAN(
		AC_DEFINE(USE_LITTLE_ENDIAN, 0, [big-endian]),
		AC_DEFINE(USE_LITTLE_ENDIAN, 1, [little-endian]),
		AC_MSG_ERROR(unknown endianess not supported),
		AC_MSG_ERROR(universial endianess not supported)
	)
	AC_DEFINE(HAVE_YAUS, 1, [Whether you have YAUS])
	PHP_REQUIRE_CXX()
	PHP_SUBST(YAUS_SHARED_LIBADD)
	PHP_ADD_LIBRARY(stdc++, 1, YAUS_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(sphinx, libsphinx/src, YAUS_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(stemmer, libsphinx/libstemmer_c, YAUS_SHARED_LIBADD)
	PHP_NEW_EXTENSION(yaus, yaus.cpp, $ext_shared)
fi
