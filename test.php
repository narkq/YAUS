<?php
$words = array(
	'сучка',
	'сучкой',
	'сучку',
	'сучке',
	'директором',
	'директорам',
	'директору',
	'бухгалтерский',
	'бухгалтерская',
	'бухгалтерское',
	'домашний',
	'домашная',
	'домашнее',
	'менеджер',
	'менеджеру',
	'менеджера',
	'менеджере',
	'менеджером',
	'менеджерам',
	'менеджерами',
	'сталевар',
	'сталевару',
	'сталевара',
	'сталеваре',
	'сталеваром',
	'сталеварам',
	'сталеварами',
);

$syscall_path = './libsphinx/src/stemword';
foreach ($words as $word)
{
	$right = substr(`$syscall_path $word`, 0, -1);
	$result = stemword_ru_cp1251($word);
	if ($result !== $right)
	{
		echo "FAIL!\t($word)\t$result\tinstead of\t$right\n";
	}
	else
	{
		echo "PASS \t($word)\n";
	}
}

$c = 50;
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
