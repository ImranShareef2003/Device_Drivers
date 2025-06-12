#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#define size 1024
static dev_t dev;
static struct cdev mycdev;
static char kernelbuffer[size];
static __init int first(void);
static __exit void last(void);
static int open (struct inode *inode, struct file *file);
static int release (struct inode *inode, struct file *file);
static ssize_t read (struct file *file, char __user *userbuffer, size_t count, loff_t *offset);
static ssize_t Write (struct file *file, const char __user *userbuffer, size_t count, loff_t *offset);
static const struct file_operations fops = {				
	.owner	 = THIS_MODULE,						
	.open	 = open,					
	.release = release,					
	.read	 = read,					
	.write	 = Write,
};
static int open (struct inode *inode, struct file *file)
{
   pr_info("DEVICE FILE IS OPENED\n");
   return 0;
}
static int release (struct inode *inode, struct file *file)
{
  pr_info("DEVICE FILE IS CLOSED\n");
  return 0;
}
static ssize_t read (struct file *file, char __user *userbuffer, size_t count, loff_t *offset)
{
  pr_info("I AM IN A READING MODE\n");
  if(copy_to_user(userbuffer,kernelbuffer, count))
  {
    pr_info("DATA READING ERROR\n");
  }
  pr_info("DATA READING IS COMPLETED\n");
  return 0;
}
static int length=0;
static ssize_t Write (struct file *file, const char __user *userbuffer, size_t count, loff_t *offset)
{
  pr_info("I AM WRITING MODE\n");
  if(copy_from_user(kernelbuffer+length,userbuffer,count))
  {
    pr_info("DATA WRITING ERROR\n");
  }
  length=length+count;
  pr_info("DATA WRITING IS COMPLETED\n");
  pr_info("%s",kernelbuffer);
  return 0;
}
static __init int first(void)
{
  pr_info("I AM FIRST FUNCTION\n");
  if(alloc_chrdev_region(&dev,0, 1,"rs45")<0)
  {
    pr_info("DEVICE FILE IS NOT CREATED\n");
  }
  pr_info("MAJOR NUMBER is :%d\n",MAJOR(dev));
  pr_info("MINOR NUMBER is :%d\n",MINOR(dev));
  cdev_init(&mycdev, &fops);
  cdev_add(&mycdev, dev, 1);
  return 0;
}
static __exit void last(void)
{
   pr_info("I AM IN LAST FUNCTION\n");
   cdev_del(&mycdev);
   unregister_chrdev_region(dev, 1);
}
module_init(first);
module_exit(last);
MODULE_LICENSE("GPL");

