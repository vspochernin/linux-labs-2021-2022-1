#ifndef READ_H
#define READ_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "doc.h"

static ssize_t device_read(struct file *filp,char __user * buff, size_t len, loff_t * offset)
{
	if (*buff_Ptr == 0)
	{
		buff = "";
		return 0;
	}
	printk(KERN_INFO "Get\n");
    	static int bytes = 0;
	int size = 0;

	if(!is_fwd_dir) // if bakward
	{
		while (*buff_Ptr != '\0') // well, it is size
		{
			++buff_Ptr;
			++size;
		}
		while (size != 0)
		{
			--size;
			--buff_Ptr;

			put_user(*buff_Ptr, buff++);

			--len;
			++bytes;
		}
	}
	else if (is_fwd_dir){

		while (*buff_Ptr != '\0' && *buff_Ptr != '\n')
		{
			put_user(*(buff_Ptr++), buff++);
			--len;
			++bytes;
		}
	}
    put_user('\n', buff++);
	printk(KERN_INFO "Bytes read: %d\n", bytes - 1);
	return bytes;
}
#endif
