#include <stdio.h>
#include <string.h>
#include "ioctl.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int n;
	char rbuff[100];
	char userbuf[100];
	printf("I am in user code\n");
	while(1)
	{
		printf("1.Read Operation\n2.Write Operation\n3.IOCTL Get\n4.IOCTL Set\n5.Exit\n");
		printf("Enter the operation to be execute\n");
		scanf("%d",&n);
		getchar();
		int fd=open("/dev/program11",O_RDWR,0644);
		switch(n)
		{
			case 1:
				read(fd,rbuff,sizeof(rbuff));
				printf("Received string from kernel %s\n",rbuff);
				break;
			case 2:
				printf("Enter the String to send to Kernel\n");
				fgets(userbuf,sizeof(userbuf),stdin);
				write(fd,userbuf,strlen(userbuf));
				break;
			case 3:
				int get;
				ioctl(fd,ioctl_get,&get);
				printf("IOCTL received %d Value from Kernel\n",get);
				break;
			case 4:
				int set;
				printf("Enter the data to set\n");
				scanf("%d",&set);
				getchar();
				ioctl(fd,ioctl_set,&set);
				printf("Data Setted Successfully\n");
				break;
			case 5:
				printf("Exited Successfully\n");
				exit(1);
			default:
				printf("Entered Wrong Operation\n");
				break;
		}		
		close(fd);
		memset(rbuff,0,sizeof(rbuff));
		memset(userbuf,0,sizeof(userbuf));
	}
	return 0;				
}
