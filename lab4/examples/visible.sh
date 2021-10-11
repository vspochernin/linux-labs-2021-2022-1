#!/bin/sh
display()
{
	local local_var=100
	global_var=blessen
	echo "локальная переменная внутри функции равна $local_var"
	echo "глобальная переменная внутри функции равна $global_var"
}
echo "==============внутри функции============="
display
echo "======вне функции======="
echo "локальная переменная вне функции равна $local_var"
echo "глобальная переменная вне функции равна $global_var"
