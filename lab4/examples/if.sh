#!/bin/sh
echo "Введите имя пользователя:"
read username
if [ "$username" = "blessen" ]
then
	echo "Успешно!!! Вы зашли."
else
	echo "Извините, неправильное имя пользователя."
fi
