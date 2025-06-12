#include<linux/init.h>
#include<linux/module.h>

static int first(void)
{
	printk("are you getting\n");	
	return 0;
}


static void end(void)
{
	printk("okay byeeeeee\n");
	
}

module_init(first);
module_exit(end);

MODULE_LICENSE("GPL");
