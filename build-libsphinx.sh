#!/bin/bash
set -e
set -x

SPHINX_VERSION=2.2.10

if [[ ! -d libsphinx ]]
then
    wget http://sphinxsearch.com/files/sphinx-$SPHINX_VERSION-release.tar.gz
    tar zxf sphinx-$SPHINX_VERSION-release.tar.gz
    rm sphinx-$SPHINX_VERSION-release.tar.gz
    mv sphinx-$SPHINX_VERSION-release libsphinx
fi
pushd libsphinx
if [[ ! -d libstemmer_c/libstemmer ]]
then
    wget http://snowball.tartarus.org/dist/libstemmer_c.tgz
    tar zxf libstemmer_c.tgz
    rm libstemmer_c.tgz
fi
uname -s
OS_FAMILY=$(uname -s)
if [[ "$OS_FAMILY" != "Darwin" ]]
then
	patch -p1 < ../patches/sphinx-$SPHINX_VERSION.patch
	./buildconf.sh
fi
./configure --without-mysql --without-libexpat --without-iconv --with-libstemmer
make -j2
popd
