#!/bin/bash
SPHINX_VERSION=2.0.6
wget http://sphinxsearch.com/files/sphinx-$SPHINX_VERSION-release.tar.gz \
	&& tar zxf sphinx-$SPHINX_VERSION-release.tar.gz \
	&& rm sphinx-$SPHINX_VERSION-release.tar.gz \
	&& mv sphinx-$SPHINX_VERSION-release libsphinx \
	&& pushd libsphinx \
	&& wget http://snowball.tartarus.org/dist/libstemmer_c.tgz \
	&& tar zxf libstemmer_c.tgz \
	&& rm libstemmer_c.tgz \
	&& patch -p1 < patches/sphinx-$SPHINX_VERSION-fPIC.patch \
	&& ./buildconf.sh \
	&& ./configure --without-mysql --without-libexpat --without-iconv --with-libstemmer \
	&& make -j2 \
	&& popd
