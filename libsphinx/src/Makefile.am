SRC_SPHINX = sphinx.cpp sphinxexcerpt.cpp sphinxquery.cpp \
	sphinxsoundex.cpp sphinxmetaphone.cpp sphinxstemen.cpp sphinxstemru.cpp sphinxstemcz.cpp \
	sphinxutils.cpp md5.cpp sphinxstd.cpp sphinxsort.cpp sphinxexpr.cpp sphinxfilter.cpp \
	sphinxsearch.cpp sphinxrt.cpp

noinst_LIBRARIES = libsphinx.a
libsphinx_a_SOURCES = $(SRC_SPHINX)

bin_PROGRAMS = stemword
#noinst_PROGRAMS = tests

stemword_SOURCES = stemword.cpp
#tests_SOURCES = tests.cpp

BUILT_SOURCES = extract-version
.PHONY: extract-version
extract-version:
	/bin/sh svnxrev.sh ..

if USE_LIBSTEMMER
LIBSTEMMER_LIBS = $(top_srcdir)/libstemmer_c/libstemmer.a
AM_CPPFLAGS = -I$(top_srcdir)/libstemmer_c/include -DSYSCONFDIR="\"$(sysconfdir)\"" -DDATADIR="\"$(localstatedir)/data\"" -fPIC
else
LIBSTEMMER_LIBS =
AM_CPPFLAGS = -DSYSCONFDIR="\"$(sysconfdir)\"" -DDATADIR="\"$(localstatedir)/data\"" -fPIC
endif

COMMON_LIBS = libsphinx.a $(LIBSTEMMER_LIBS) $(MYSQL_LIBS) $(PGSQL_LIBS)
LDADD = $(COMMON_LIBS)
