#ifndef ANYLYSE_H
#define ANYLYSE_H
#include "doc.h"

bool str_cmp(const char* str1, const char* str2)
{
	while ( (*(str1) != '\0') && (*(str2) != '\0'))
	{
		if (*(str1) != *(str2))
		{
			return false;
		}
		++str1;
		++str2;
	}
	return true;
}


void direction_backward(void)
{
	printk(KERN_ALERT "Back direction\n");
	is_fwd_dir = false;
}

void direction_forward(void)
{
	printk(KERN_ALERT "Forward direction\n");
	is_fwd_dir = true;
}

void analyse(char *new_msg)
{
	if (str_cmp(new_msg,"direction back"))
	{
		direction_backward();
	}
	if (str_cmp(new_msg,"direction forward"))
	{
		direction_forward();
	}
}	

#endif

