#!/bin/bash
cat $1 | tail -n+$3 | head -n $2

# Мы перенаправляем содержимое файла, переданного в первом параметре команде tail.

# В команде tail есть ключ -n, который показывает последние n строк, НО если написать -n+NUM, то
# будут выведены строки, начиная с NUM. NUM передается третим параметром.

# Все это передается команде head, которая выводит первые несколько строк, количество которых
# указывается с помощью ключа -n (и передается вторым параметром). 

# Итого имеем скрипт, который имеет параметры:
# 1 - название файла, 2 - сколько строк вывести, 3 - начиная с какой строки.
