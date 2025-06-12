#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static int val=1;
module_param(val,int,0644);
static int first(void)
{
	printk(KERN_INFO"I am in first\n");
	printk(KERN_INFO"The value is %d\n",val);
	return 0;
}
static void end(void)
{
	printk(KERN_INFO"I am in end\n");
}
module_init(first);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("THIS IS ABOUT COMMAND LINE ARDUMENTS");
MODULE_AUTHOR("ME");
