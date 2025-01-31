#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main(){
	pid_t childpid = fork();
	
	if (childpid == 0){
		printf("Current runnning process: CHILD PROCESS\n");
		printf("Process ID: %d\n",getpid());
		printf("Parent process ID: %d\n",getppid());
		printf("----------------------------------------\n");
	}
	
	else if (childpid > 0){
		printf("Current running process: PARENT PROCESS\n");
		printf("Process ID: %d\n",getpid());
		printf("Child process ID: %d\n",childpid);
		printf("----------------------------------------\n");
		printf("Parent process is stopped at the moment,\nChild process running...\n");
		wait(NULL);
	}
	
	else if (childpid < 0){
		printf("Child process creation UNSUCCESSFUL!\n");
		printf("----------------------------------------\n");
	}
	
	exit(0);
}

