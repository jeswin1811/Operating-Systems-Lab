#include<stdio.h>

void main(){
	float avgw=0, avgt=0;
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int btime[n];
	for(int i=0; i<n; i++){
		printf("Enter the burst time of process %d: ",i+1);
		scanf("%d",&btime[i]);
	}
	int wtime[n];
	wtime[0]=0;
	for(int i=1; i<n; i++){
		wtime[i] = wtime[i-1] + btime[i-1];
		avgw = avgw + wtime[i];
	}
	int ttime[n];
	for(int i=0; i<n; i++){
		ttime[i] = btime[i] + wtime[i];
		avgt = avgt + ttime[i];
	}
	printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
	for(int i=0; i<n; i++){
		printf("\n\t%d\t\t%d\t\t%d\t\t%d\n",i,btime[i],wtime[i],ttime[i]);
	}
	printf("\n");
	printf("Average turn around time = %f\n",avgt/n);
	printf("Average waiting time = %f\n",avgw/n);
	int temp = 0;
	printf("\nGANTT CHART: \n");
	printf("\n\t-----------------------------------\n");
	for(int i=0; i<n; i++){
		printf("\t  P[%d]",i+1);
	}
	printf("\n\t-----------------------------------\n");
	printf("\t%d",temp);
	for(int i=0; i<n; i++){
		temp = temp + btime[i];
		printf("\t%d",temp);
	}
	printf("\n");
}
