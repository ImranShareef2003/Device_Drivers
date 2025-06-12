#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "add.h"
static int var1=10;
static int var2=20;
module_param(var1,int,0644);
module_param(var2,int,0644);
int sub(int a,int b)
{
	return a-b;
}
EXPORT_SYMBOL(sub);
 static int first(void)
 {
 	pr_warn("I am in ADD\n");
 	pr_alert("Sum is %d\n",add(var1,var2));
 	return 0;
 }
 static void end(void)
 {
 	pr_info("I Ended ADD\n");
 }
 
 module_init(first);
 module_exit(end);
 
 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("ABHILASH ADD");
 MODULE_DESCRIPTION("THIS IS EXPORT CODE ADD");
