#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{	
	printf("I am in Main Function\n");
	
	char userbuf[100],rbuf[100];	
	printf("Enter the String to send\n");
	fgets(userbuf,sizeof(userbuf),stdin);
	
	
	int fd=open("/dev/program8_dev",O_RDWR,0644);
	write(fd,userbuf,strlen(userbuf));
	close(fd);
	
	fd=open("/dev/program8_dev",O_RDWR,0644);
	read(fd,rbuf,sizeof(rbuf));
	printf("Recevied from Kernel is %s",rbuf);
	close(fd);
	
	return 0;
}
