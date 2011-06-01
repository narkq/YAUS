# Yet Another Useless Stemmer

This is a really clumsy attempt at porting Sphinx built-in stemmers to PHP without losing much in performance.

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

Do not forget to add `yaus.so` to your `php.ini` file!

After this you might want to run included `test.php`, it's easy and doesn't require anything besides this extension.

	php -f test.php

Now the extension adds just one function, it works like this:

    <?php
    echo stemword_ru_cp1251('неожиданность');
