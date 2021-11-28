
#ifndef CHARDEV_H
#define CHARDEV_H
#include <linux/ioctl.h>

#define MAJOR_NUM 230

#define IOCTL_FILE_DELETE _IO(MAJOR_NUM, 0)

#define IOCTL_WRITE_FILE _IOR(MAJOR_NUM, 1, char *)

#define IOCTL_READ_FILE _IOR(MAJOR_NUM, 2, char *)

#define DEVICE_FILE_NAME "char_dev"

#endif
