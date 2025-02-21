#include<stdio.h>
#include<stdlib.h>

int ch, mutex=1, full=0, empty=3, x=0;

int wait(int s){
	return(--s);
}

int signal(int s){
	return(++s);
}

void producer(){
	mutex = wait(mutex);
	empty = wait(empty);
	full = signal(full);
	printf("\nPRODUCER PRODUCED ITEM %d\n",++x);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("\nCONSUMER CONSUMED ITEM %d\n",x--);
	mutex = signal(mutex);
}

void main(){
	while(1){
		printf("\n1. PRODUCE\n2. CONSUME\n3. EXIT\n");
		printf("\nEnter choice: "); 
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if((mutex==1) && (empty!=0)){
					producer();
				}
				else{
					printf("\nBuffer is full...\n");
				}
				break;
			case 2:
				if((mutex==1) && (full!=0)){
					consumer();
				}
				else{
					printf("\nBuffer is empty...\n");
				}
				break;
			case 3:
				printf("\nExiting...\n");
				exit(0);
				break;
			default: 
				printf("\nInvalid Choice\n");
				
		}
	}
}
