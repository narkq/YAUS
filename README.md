# Yet Another Useless Stemmer

This is a really clumsy attempt at porting Sphinx built-in stemmers to PHP without losing much in performance.

For now **only** built-in english and russian stemmers are supported.
The rest (soundex, double metaphone, libstemmer and unicode versions of these) are likely to be added soon.

Installation procedure is as usual, but you need to build `libsphinx` first:

    cd <extension path>
    ./build-libsphinx.sh
    phpize
    ./configure
    make
    sudo make install

Make sure you've got `wget` and `autoconf` installed, `build-libsphinx.sh` and `phpize` scripts just won't work otherwise!

Do not forget to add `yaus.so` to your `php.ini` file!

Now the extension adds just three functions, they work like this:

    <?php
    // gets the stem of a russian word
    function stemword_ru($russian_word, $is_utf8);
    // gets the stem of an english word
    function stemword_en($english_word);
    // gets the stem of a russian or english word
    function stemword_enru($russian_or_english_word, $is_utf8);

### CHANGELOG

*	v 0.2.0

	Added `$is_utf8` parameter to stem functions for russian words.

*	v 0.1

	Yay, first release!
