#ifndef WRITE_H
#define WRITE_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include "doc.h"
#include "analyse.h"

static ssize_t device_write(struct file *filp, const char __user * buff, size_t len, loff_t * offset)
{
	int i;
	char new_msg[BUF_LEN];

	printk(KERN_INFO "Saving contents: [lenght=%d]", (int)(len - 1) );
	for (i = 0; i < len && i < BUF_LEN; i++)
	{
		get_user(new_msg[i], buff + i);
	}
	
	analyse(new_msg);
	
	for (i = 0; i < BUF_LEN; i++)
	{
		get_user(msg[i], " ");
	}
	for (i = 0; i < len && i < BUF_LEN; i++)
	{
		get_user(msg[i], buff + i);
	}

	buff_Ptr = msg;
	
	return i;
}
#endif
