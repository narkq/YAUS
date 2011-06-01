# Yet Another Useless Stemmer

This is a really clumsy attempt at porting Sphinx built-in stemmers to PHP without losing much in performance.

Installation procedure is as usual:

    cd <extension path>
    phpize
    ./configure
    make
    sudo make install

Do not forget to add `yaus.so` to your `php.ini` file!

If you want to run included `test.php`, you should build `stemword` utility as following:

    cd <extension path>/libsphinx
    ./buildconf.sh
    ./configure
    make

Now the extension adds just one function, it works like this:

    <?php
    echo stemword_ru_cp1251('неожиданность');
