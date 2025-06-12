#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>  
#include "ioctl.h"   
static dev_t dev;
static struct cdev mycdev;
char kernelbuf[100];

//Function Prototypes
static int __init first(void);
static void __exit end(void);
static int my_open(struct inode *inode, struct file *file);
static ssize_t my_read(struct file *file, char __user *userbuf, size_t count, loff_t *offset);
static ssize_t my_write(struct file *file, const char __user *userbuf, size_t count, loff_t *offset);
static int my_close(struct inode *, struct file *);
static long ioctl_operation(struct file *file, unsigned int cmd, unsigned long arg);

static struct file_operations fp=
{
	.owner=THIS_MODULE,
	.read= my_read,
	.write=my_write,
	.open=my_open,
	.release=my_close,
	.unlocked_ioctl=ioctl_operation,
};
static int my_open(struct inode *inode, struct file *file)
{
	pr_info("Device File is Opened\n");
	return 0;
}
static int my_close(struct inode *inode, struct file *file)
{
	pr_info("Device File is Closed\n");
	return 0;
}
static ssize_t my_read(struct file *file, char __user *userbuf, size_t count, loff_t *offset)
{
	pr_info("I am in My_read Function\n");
	if(copy_to_user(userbuf,kernelbuf,count))
	{
		pr_info("Data Reading ERROR\n");
	}
	pr_info("Data Reading Completed\n");
	return 0;
}
static ssize_t my_write(struct file *file, const char __user *userbuf, size_t count, loff_t *offset)
{
	pr_info("I am in My_write Function\n");
	if(copy_from_user(kernelbuf,userbuf,count))
	{
		pr_info("Data Writing ERROR\n");
	}
	kernelbuf[count]='\0';
	pr_info("Received %s",kernelbuf);
	pr_info("Data Writting Completed\n");
	return count;
}
static int set=0;
static int get=0;
static long ioctl_operation(struct file *file, unsigned int cmd, unsigned long arg)
{
	switch(cmd)
	{
		case ioctl_set:
				copy_from_user(&get,(int *)arg,sizeof(get));
				pr_info("Setted in Kernel %d\n",get);
				break;
		case ioctl_get:
				set=get;
				copy_to_user((int *)arg,&set,sizeof(set));
				break;
		default:
				pr_info("Invalid in Kernel\n");
				break;
	}
	return 0;
}
static int __init first(void)
{
	pr_info("I am in Program11\n");
	if(alloc_chrdev_region(&dev,0,1,"progra11")<0)
	{
		pr_info("Major Number Not Created\n");
	}
	pr_info("MAJOR No is %d\n",MAJOR(dev));
	pr_info("MINOR No is %d\n",MINOR(dev));
	
	cdev_init(&mycdev,&fp);
	if(cdev_add(&mycdev,dev,1)<0)
	{
		pr_info("Cdev_add failed\n");
	}
	return 0;
}
static void __exit end(void)
{
	unregister_chrdev_region(dev,1);
	cdev_del(&mycdev);
	pr_info("I ended Program11\n");
}

module_init(first);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAI");
MODULE_DESCRIPTION("THIS IS SIMPLE IOCTL CHARACTER DEVICE CODE");
