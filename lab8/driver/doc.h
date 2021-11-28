#ifndef DOC_H
#define DOC_H
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "char_dev.h"


int init_module(void);
void cleanup_module(void);

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);

static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);
ssize_t device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param);

#define SUCCESS 0
#define DEVICE_NAME "char_dev"
#define BUF_LEN 81

static int Major;
static int Device_Open = 0;
static bool is_dev_opened = false;

static char msg[BUF_LEN];
static char *buff_Ptr;
static bool is_fwd_dir = true;


static struct file_operations fops = {
        .read = device_read,
        .write = device_write,
	.unlocked_ioctl = device_ioctl,
        .open = device_open,
        .release = device_release };

#endif
