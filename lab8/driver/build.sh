#/bin/sh
gcc ioctl.c -o ioctl
mknod char_dev c 230 0
