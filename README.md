# Yet Another Useless Stemmer

This is a really clumsy attempt at porting Sphinx built-in stemmers to PHP without losing much in performance.

Almost every stemming algorithm that's implemented in Sphinx as of 2.0.6-release version is available here as well (`stem_cz` is an exception).

Installation procedure is as usual, but you need to build `libsphinx` first:

    cd <extension path>
    ./build-libsphinx.sh
    phpize
    ./configure
    make
    sudo make install

Make sure you've got `wget` and `autoconf` installed, `build-libsphinx.sh` and `phpize` scripts just won't work otherwise!

Also, C++ compiler is required to build this extension (and `libsphinx` too). GCC and MSVC 9.0 is known to work.

If you build this as a shared library, do not forget to add `yaus.so` to your `php.ini` file!

API is pretty old-fashioned, this may be changed in the future.

    <?php
    /**
     * gets the stem of a russian word
     */
    function stemword_ru($russian_word, $is_utf8);

    /**
     * gets the stem of an english word
     */
    function stemword_en($english_word);

    /**
     * gets the stem of a russian or english word
     */
    function stemword_enru($russian_or_english_word, $is_utf8);

    /**
     * gets the stem of an english word using soundex algorithm
     */
    function stemword_soundex($english_word);

    /**
     * gets the stem of an english word using metaphone algorithm
     */
    function stemword_dmetaphone($english_word, $is_utf8);

    /**
     * initializes the snowball stemmer
     * returns a resource
     */
    function stemword_snowball_new($algorithm, $encoding);

    /**
     * gets the stem of a word using stemmer resource
     */
    function stemword_snowball_stem($stemmer, $word);

    /**
     * frees the stemmer resource
     */
    function stemword_snowball_delete($stemmer);

### CHANGELOG

*	v 0.2.1

	Minor portability fixes.

*	v 0.2.0

	Added `$is_utf8` parameter to stem functions for russian words.

*	v 0.1

	Yay, first release!


### TODO

*	sphinx 2.1.1-beta build

*	lemmatizer interface

*	travis build setup

*	OOP-style interface
