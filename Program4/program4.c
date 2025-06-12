#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static char *str="CDAC";
module_param(str,charp,0644);
static int first(void)
{
	printk(KERN_INFO"I am in first\n");
	printk(KERN_INFO"The string is %s\n",str);
	return 0;
}
static void end(void)
{
	printk(KERN_INFO"I am in end\n");
}
module_init(first);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("THIS IS ABOUT COMMAND LINE ARDUMENTS for String");
MODULE_AUTHOR("ME");
