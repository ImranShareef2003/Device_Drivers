#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static int first(void)
{
	printk(KERN_INFO "Hello Everyone I AM INFO\n");
	printk(KERN_ALERT "EVERYONE BE ALERT\n");
	printk(KERN_WARNING "Mothers promise horizantally cut\n");
	printk(KERN_ERR "This is an Error 404\n");
	return 0;
}

static void end(void)
{
	pr_info("I am ending the info\n");
}

module_init(first);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple printk module demo");
MODULE_AUTHOR("SAI");
