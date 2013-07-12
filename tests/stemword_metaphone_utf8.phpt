--TEST--
stemword_dmetaphone for utf-8
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$word_list = array_map(
	function($word) {
		return substr($word, 0, -1);
	},
	file(__DIR__.'/words_for_metaphone.txt')
);
foreach ($word_list as $word)
{
	var_dump(stemword_dmetaphone($word, true));
}
?>
--EXPECT--
string(3) "LTR"
string(2) "PF"
string(2) "SF"
string(2) "LM"
string(2) "XP"
string(1) "N"
string(1) "N"
string(3) "ARL"
string(2) "NM"
string(3) "RNK"
string(2) "0M"
string(3) "XNJ"
string(4) "KLSL"
string(4) "KRMN"
string(4) "ANRJ"
string(3) "JST"
string(2) "LK"
string(2) "LK"
string(2) "F0"
string(2) "FT"
string(2) "KR"
string(1) "X"
string(1) "A"
string(2) "AR"
string(3) "NLJ"
string(3) "SPR"
string(3) "SSL"
