#include <stdio.h>
#include <string.h>
#include "ioctl.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
		int n,n1;
		int result=0;
		printf("I am in user code\n");
		int fd=open("/dev/program12",O_RDWR,0644);
		int arr[3];	
		while(1)
		{
			printf("1.set\n2.get\n3.exit\n");
			printf("Choose set or get\n");
			scanf("%d",&n1);
			switch(n1)
			{
				case 1:
					printf("The third Value is the operation Number\n");
					printf("Select the third Value from below Options\n");
					printf("1.Add Operation\n2.Sub Operation\n3.Multlipy Operation\n4.Division Operation\n5.Modulus\n");
					for(int i=0;i<3;i++)
					{	
						printf("Enter %d Value\n",(i+1));
						scanf("%d",&arr[i]);
					}
					ioctl(fd,ioctl_set,arr);
					break;
				case 2:
					ioctl(fd,ioctl_get,&result);
					printf("result=  %d\n",result);
					break;
				case 3:
					printf("Exited Successfully\n");
					exit(1);
					close(fd);
			}
		}
	return 0;				
}
