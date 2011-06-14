# Yet Another Useless Stemmer

This is a really clumsy attempt at porting Sphinx built-in stemmers to PHP without losing much in performance.

For now **only** single-byte built-in english and russian stemmers are supported.
The rest (soundex, double metaphone, libstemmer and unicode versions of these) are likely to be added soon.

Installation procedure is as usual, but you need to build `libsphinx` first:

    cd <extension path>
    cd libsphinx
    ./buildconf.sh
    ./configure
    make
    cd ..
    phpize
    ./configure
    make
    sudo make install

Make sure you've got `autoconf` installed, `buildconf` and `phpize` scripts just won't work otherwise!

Do not forget to add `yaus.so` to your `php.ini` file!

After this you might want to run included `test.php`, it's easy and doesn't require anything besides this extension.

	php -f test.php

Now the extension adds just three functions, they work like this:

    <?php
	// get stem of a russian word in cp1251 encoding
    echo stemword_ru('неожиданность');
	// get stem of an english word
    echo stemword_en('googling');
	// get stem of a russian or english word
	echo stemword_enru('дружелюбие');
	echo stemword_enru('supposedly');
