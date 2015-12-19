# Yet Another Useless Stemmer

[![Build Status](https://secure.travis-ci.org/narkq/YAUS.png?branch=master)](http://travis-ci.org/narkq/YAUS)

## Introduction

This is a really clumsy attempt at porting Sphinx built-in stemmers to PHP without losing much in performance.

Almost every stemming algorithm that's implemented in Sphinx as of 2.0.6-release version is available here as well (`stem_cz` is an exception).

## Building

Building procedure for Unix-like systems is quite usual, but you need to build `libsphinx` first:

    cd <extension path>
    ./build-libsphinx.sh
    phpize
    ./configure
    make
    sudo make install

Make sure you've got `wget` and `autoconf` installed, `build-libsphinx.sh` and `phpize` scripts just won't work otherwise!

Also, C++ compiler is required to build this extension (and `libsphinx` too). GCC is known to work.

If you build this as a shared library, do not forget to add `yaus.so` to your `php.ini` file!

## Using

API is pretty old-fashioned, this may be changed in the future.

    <?php
    /**
     * gets the stem of a russian word
     */
    function stemword_ru($russian_word);

    /**
     * gets the stem of an english word
     */
    function stemword_en($english_word);

    /**
     * gets the stem of a russian or english word
     */
    function stemword_enru($russian_or_english_word);

    /**
     * gets the stem of an english word using soundex algorithm
     */
    function stemword_soundex($english_word);

    /**
     * gets the stem of an english word using metaphone algorithm
     */
    function stemword_dmetaphone($english_word);

    /**
     * initializes the snowball stemmer
     * returns a resource
     */
    function stemword_snowball_new($algorithm, $encoding = 'UTF_8');

    /**
     * gets the stem of a word using stemmer resource
     */
    function stemword_snowball_stem($stemmer, $word);

    /**
     * gets the list of available stemming algorithms via libstemmer
     */
    function stemword_snowball_algorithm_list();

    /**
     * frees the stemmer resource
     */
    function stemword_snowball_delete($stemmer);

## CHANGELOG

*	v 0.3.3

	* updated libsphinx to 2.2.10

	* changed `stemword_dmetaphone` to be compatible with new libsphinx

	* fixed building procedure yet again

*	v 0.3.2

	* fixed building procedure with new automake

*	v 0.3.1

	* fixed phpinfo() formatting

*	v 0.3.0

	* added the rest of builtin sphinx stemmers (except `stem_cz`)

	* added stemmers from `libsphinx_c`

	* fixed memory allocation for strings that passed into russian utf-8 stemmer

	* added Windows support (build process is not documented yet); [prebuilt shared library](https://drive.google.com/folderview?id=0Bx7fvWqnm1IEenFlTFl3eWM5NG8&usp=sharing) is available for download

*	v 0.2.1

	Minor portability fixes.

*	v 0.2.0

	Added `$is_utf8` parameter to stem functions for russian words.

*	v 0.1

	Yay, first release!


## TODO

*	building guide for Windows

*	lemmatizer interface

*	OOP-style interface
