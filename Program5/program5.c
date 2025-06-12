#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
int add(int a,int b)
{
	return a+b;
}
EXPORT_SYMBOL(add);
 static int first(void)
 {
 	pr_warn("I am in Program 5\n");
 	return 0;
 }
 static void end(void)
 {
 	pr_info("I Ended Program 5\n");
 }
 
 module_init(first);
 module_exit(end);
 
 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("ABHILASH");
 MODULE_DESCRIPTION("THIS IS EXPORT CODE");
