#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> /* open */
#include <unistd.h> /* exit */
#include <sys/ioctl.h> /* ioctl */
#include "char_dev.h"

void ioctl_write_file(int file_desc, int file_write_desc)
{
	char message[80];
	ssize_t fbytes_read = read(file_write_desc,message,80);
	if (fbytes_read < 0)
		{ exit(-1);} else
	{message[fbytes_read] = '\0';}
	int ret_val;
	lseek(file_write_desc,0,SEEK_SET);
	ret_val = ioctl(file_desc, IOCTL_WRITE_FILE, message);

	if (ret_val < 0) {
		printf("ioctl_write_file failed:%d\n", ret_val);
		exit(-1);
	}
}

void ioctl_delete_file(int file_desc)
{
	int ret_val;
	ret_val = ioctl(file_desc, IOCTL_FILE_DELETE);
	if (ret_val < 0) {
		printf("ioctl_file_delete failed:%d\n", ret_val);
		exit(-1);
	}
}

void ioctl_read_file(int file_desc)
{
	int ret_val;
	char message[80];

	ret_val = ioctl(file_desc, IOCTL_READ_FILE, message);
	if (ret_val < 0) {
		printf("ioctl_read_file failed:%d\n", ret_val);
		exit(-1);
	}
	printf("read_file message:%s\n", message);
}

/*
* Main - Call the ioctl functions
*/
int main()
{
	int file_desc, file_data_desc,file_back_desc,
	file_forward_desc,ret_val;
	char *msg = "Message passed by ioctl\n";
	char *cmp_forw = "direction forward";
	char *cmp_back = "direction back";
	file_desc = open(DEVICE_FILE_NAME, 0);
	if (file_desc < 0) {
		printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
		exit(-1);
	}
	file_data_desc = open("data", 0);
	if (file_data_desc < 0) {
		printf("Can't open internal file-container\n");
		exit(-1);
	}
	file_forward_desc = open("forward", 0);
	if (file_forward_desc < 0) {
		printf("Can't open internal file-container\n");
		exit(-1);
	}
	file_back_desc = open("backward", 0);
	if (file_back_desc < 0) {
		printf("Can't open internal file-container\n");
		exit(-1);
	}
	
	ioctl_write_file(file_desc, file_data_desc);
	ioctl_read_file(file_desc);
	
	
	ioctl_write_file(file_desc, file_back_desc);
	ioctl_read_file(file_desc);	

	ioctl_write_file(file_desc, file_forward_desc);
	ioctl_read_file(file_desc);


	ioctl_delete_file(file_desc);
	ioctl_read_file(file_desc);

	
	ioctl_write_file(file_desc, file_data_desc);
	ioctl_read_file(file_desc);

	close(file_desc);
	close(file_data_desc);
	close(file_back_desc);
	close(file_forward_desc);
	return 0;
}
