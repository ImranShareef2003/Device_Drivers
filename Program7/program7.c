#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>
static dev_t dev;
static int __init first(void)
{
	printk("I am in program7\n");
	if(alloc_chrdev_region(&dev,0,1,"program7")<0)
	{
		pr_info("Dev Numbers Not Created\n");
	}
	pr_info("The Major Number is %d\n",MAJOR(dev));
	pr_info("The Minor Number is %d\n",MINOR(dev));
	return 0;
}
static void __exit end(void)
{
	unregister_chrdev_region(dev,1);
	pr_info("I ended program7\n");
}

module_init(first);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("IMRAN");
MODULE_DESCRIPTION("THIS IS DEVICE NUMBER PROGRAM");
