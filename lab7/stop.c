/*
* stop.c - Пример модуля, исходный текст которого размещен в нескольких файлах
*/
#include <linux/init.h>
#include <linux/kernel.h> /* Все-таки мы пишем код ядра! */
#include <linux/module.h> /* Необходим для любого модуля ядра */
void cleanup_module(void)
{
	printk("<1> Kernel module stop\n");
}
