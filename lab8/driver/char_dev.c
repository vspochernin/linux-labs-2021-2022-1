#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "char_dev.h"
#include "doc.h"
#include "read.h"
#include "write.h"
MODULE_LICENSE("GPL");

int init_module(void)
 {
	Major = register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops);
	if (Major < 0)
	{
		printk(KERN_ALERT "Registering device failed with %d\n", MAJOR_NUM);
		return Major;
	}
	printk(KERN_INFO "Major number - %d\n", MAJOR_NUM);
	printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, MAJOR_NUM);
	printk(KERN_INFO "Available commands:\n");
	printk(KERN_INFO "delete, dir back\n");
	printk(KERN_INFO "use 'rm /dev/%s'.\n\n", DEVICE_NAME);
	return SUCCESS;
}

void cleanup_module(void)
{
	unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
	printk(KERN_ALERT "Closing.\n\n");
}

static int device_open(struct inode *inode, struct file *file) 
{
printk(KERN_INFO "Divice open - %d\n", MAJOR_NUM);
	if (is_dev_opened)
	{
		return -EBUSY;
	}
 	++Device_Open;
	is_dev_opened = true;
	buff_Ptr = msg;
	try_module_get(THIS_MODULE);
	return SUCCESS;
}

static  int device_release(struct inode *inode, struct file *file) 
{
printk(KERN_INFO "Device release - %d\n", MAJOR_NUM);
	--Device_Open;
	is_dev_opened = false;
	module_put(THIS_MODULE);
	return 0;
}

ssize_t device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
	int i;
	switch (ioctl_num) {
	case IOCTL_FILE_DELETE:		
		device_write(file," ",80,0);
		break;
	case IOCTL_WRITE_FILE:
		device_write(file,(char*)ioctl_param,80,0);			
		break;
	case IOCTL_READ_FILE:
		i = device_read(file, (char *)ioctl_param, 80, 0);
		put_user('\0', (char *)ioctl_param + i);
		break;
	}
	return SUCCESS;
}

