 #include <fcntl.h>
 #include <unistd.h>
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 char userbuffer[]="HELLO CDAC";
 char userbuff[100];
 int main()
 {
	 
	 int fd=open("/dev/rs45",O_WRONLY,0644);
	 write(fd,userbuffer,strlen(userbuffer));
	 close(fd);
	 fd=open("/dev/rs45",O_RDONLY,0644);
	 read(fd,userbuff,sizeof(userbuff));
	 printf("RECIVED DATA IS %s ",userbuff);
	 close(fd);
	 return 0;
}
