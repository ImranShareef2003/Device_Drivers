#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static int arr[5];
static int size;
module_param_array(arr,int,&size,0644);
static int first(void)
{
 	pr_warn("I am in Program 6\n");
	for(int i=0;i<size;i++)
	{
		pr_info("Arr[%d]=%d\n",i,arr[i]);
	}
 	return 0;
 }
 static void end(void)
 {
 	pr_info("I Ended Program 6\n");
 }
 
 module_init(first);
 module_exit(end);
 
 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("ABHILASH");
 MODULE_DESCRIPTION("THIS IS EXPORT CODE");
