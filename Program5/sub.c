#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static int var3=10;
static int var4=20;
module_param(var3,int,0644);
module_param(var4,int,0644);
int sub(int,int);
 static int first(void)
 {
 	pr_warn("I am in SUB\n");
 	pr_alert("Sub is %d\n",sub(var3,var4));
 	return 0;
 }
 static void end(void)
 {
 	pr_info("I Ended SUB\n");
 }
 
 module_init(first);
 module_exit(end);
 
 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("ABHILASH SUB");
 MODULE_DESCRIPTION("THIS IS EXPORT CODE SUB");
