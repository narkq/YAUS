#!/bin/bash
set -e
set -x

SPHINX_VERSION=2.1.6

wget http://sphinxsearch.com/files/sphinx-$SPHINX_VERSION-release.tar.gz
tar zxf sphinx-$SPHINX_VERSION-release.tar.gz
rm sphinx-$SPHINX_VERSION-release.tar.gz
mv sphinx-$SPHINX_VERSION-release libsphinx
pushd libsphinx
wget http://snowball.tartarus.org/dist/libstemmer_c.tgz
tar zxf libstemmer_c.tgz
rm libstemmer_c.tgz
php-config --configure-options
WITH_FPIC=$(php-config --configure-options | grep -e --with-pic | wc -l)
if [[ "$WITH_FPIC" == "1" ]]
then
	patch -p1 < ../patches/sphinx-$SPHINX_VERSION-fPIC.patch
	patch -p1 < ../patches/sphinx-$SPHINX_VERSION-automake-compat.patch
	./buildconf.sh
fi
./configure --without-mysql --without-libexpat --without-iconv --with-libstemmer
make -j2
popd
