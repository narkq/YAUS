<?php
$enc = 'windows-1251';
$u = 'utf-8';
$words = file('wordlist.txt');
foreach ($words as $key => $word)
{
	$words[$key] = iconv($u, $enc, substr($word, 0, -1));
}

$syscall_path = './libsphinx/src/stemword';
foreach ($words as $word)
{
	$right = iconv($enc, $u, substr(`$syscall_path $word`, 0, -1));
	$result = iconv($enc, $u, stemword_ru_cp1251($word));
	if ($result !== $right)
	{
		echo "FAIL!\t($word)\t$result\tinstead of\t$right\n";
	}
	else
	{
		echo "PASS \t($word)\n";
	}
}

$c = 10;
$n = 0;

$b = microtime(true);
for ($i = 0; $i < $c; $i++)
{
	foreach ($words as $word)
	{
		`$syscall_path $word`;
		$n++;
	}
}
$t = microtime(true) - $b;
echo "system call: ".($t)."\t(".($t/$n)." per call)\n";

$b = microtime(true);
for ($i = 0; $i < $c; $i++)
{
	foreach ($words as $word)
		stemword_ru_cp1251($word);
}
$t = microtime(true) - $b;
echo "function call: ".($t)."\t(".($t/$n)." per call)\n";
