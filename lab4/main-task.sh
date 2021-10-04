#!/bin/bash
echo "Из 10й в 2ую - введие 1"
echo "Из 2й в 10ую - введите 2"
read choice
echo "Введите число, которое хотите преобразовать"
read num

result=0
power2=1
power10=1
if [ "$choice" = "2" ]
then
	# Перевод из десятичной в двоичную.
	echo "Будет выполнен перевод из двоичной в десятичную числа $num"
	while [ $num -gt 0 ]
	do
		result=$[$result + $num % 10 * $power2];
		power2=$[$power2 * 2];
		num=$[$num / 10];
	done
	echo "Результат: $result"
else	
	# Перевод из двоичной в десятичную.
	echo "Будет выполнен перевод из десятичной в двоичную числа $num"
	while [ $num -gt 0 ]
	do
		result=$[$result + $num % 2 * $power10];
		num=$[$num / 2];
		power10=$[$power10 * 10];
	done
	echo "Результат: $result"
fi
