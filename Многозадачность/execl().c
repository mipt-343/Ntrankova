#include <unistd.h>
#include <stdio.h>

main()                                                
{                                                     
	int status;                                       
	if (fork() == 0)                                  
		execl("/bin/date","date",0);	//����, �����
	wait(&status);                                    
}                  