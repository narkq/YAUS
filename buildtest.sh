#!/bin/bash
make clean && make && sudo make install && php -f ./test.php | iconv -f windows-1251 -t utf-8 > out.txt
