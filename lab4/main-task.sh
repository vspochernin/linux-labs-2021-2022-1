#!/bin/bash

if [ $# -ne 1 -o "$1" != '1' -a "$1" != '2' ]
then
	echo "Некорректные параметры"
	echo "Возможен только один параметр"
	echo "1 - перевести из 10й в 2ю"
	echo "2 - перевести из 2й в 10ю"
	exit
fi

result=0
if [ $1 -eq 1 ]
then
	echo "Будет выполнени перевод из 10й системы в 2ю"
	echo "Введите число, которое хотите перевести"
	read num
	if [[ "$num" =~ [^0-9] ]]
	then
		echo "Введено некорректно десятичное число"
		exit
	fi
	power10=1
	while [ $num -gt 0 ]
	do
		result=$[$result + $num % 2 * $power10];
		num=$[$num / 2];
		power10=$[$power10 * 10];
	done
	echo "Результат: $result"
else
	echo "Будет выполнен перевод из 2й системы в 10ю"
	echo "Введите число, которое хотите перевести"
	read num
	if [[ "$num" =~ [^01] ]]
	then
		echo "Введено некорректное двоичное число"
		exit
	fi
	power2=1
	while [ $num -gt 0 ]
	do
		result=$[$result + $num % 10 * $power2];
		power2=$[$power2 * 2];
		num=$[$num / 10];
	done
	echo "Результат: $result"
fi
