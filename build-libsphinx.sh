#!/bin/bash
SPHINX_VERSION=2.0.6
wget http://sphinxsearch.com/files/sphinx-$SPHINX_VERSION-release.tar.gz \
	&& tar zxf sphinx-$SPHINX_VERSION-release.tar.gz \
	&& rm sphinx-$SPHINX_VERSION-release.tar.gz \
	&& mv sphinx-$SPHINX_VERSION-release libsphinx \
	&& patch -p0 < patches/sphinx-$SPHINX_VERSION-fPIC.patch \
	&& pushd libsphinx \
	&& ./buildconf.sh \
	&& ./configure \
	&& make -j2 \
	&& popd
