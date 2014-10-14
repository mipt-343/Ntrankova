#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>		
//Включены дополнительные библиотеки для использования функций getpid() и getppid()

int main()
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("PID: %d\n", pid);
	printf("PPID: %d\n", ppid);

	fprintf (stderr, "Press <Enter> to continue");
	getchar();
	return 0;
}