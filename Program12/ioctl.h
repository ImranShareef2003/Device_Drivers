#define MAGIC_NUM 'a'
#define ioctl_set _IOW(MAGIC_NUM,1,int*)
#define ioctl_get _IOR(MAGIC_NUM,2,int)
