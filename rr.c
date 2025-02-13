#include<stdio.h>
void main(){
    int i, n, tq, total=0, flag=0;
    float avgwt=0, avgtat=0;
    
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    struct process{
        int pid;
        int bt;
        int tat; 
        int rt;
        int wt;
    }p[n];
    
    int timeline[100]; 
    int time_index = 0;  
    
    for(int i=0; i<n; i++){
        printf("\nEnter the process id: ");
        scanf("%d",&p[i].pid);
        printf("\nEnter the burst time: ");
        scanf("%d",&p[i].bt);
        p[i].rt = p[i].bt;
    }
    
    printf("\nEnter the time quantum: ");
    scanf("%d",&tq);
    
    while(flag != n){
        for(int i=0; i<n; i++){
            if(p[i].rt > tq){
                for(int j=0; j<tq; j++){
                    timeline[time_index++] = p[i].pid;
                }
                total += tq;
                p[i].rt -= tq;
            }
            else if(p[i].rt > 0){
                for(int j=0; j<p[i].rt; j++){
                    timeline[time_index++] = p[i].pid;
                }
                total += p[i].rt;
                p[i].rt = 0;
                p[i].tat = total;
                p[i].wt = total - p[i].bt;
                flag++;      
            }
        }
    }
    
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0; i<n; i++){
        printf("\n\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }
    printf("\n");
    printf("Average turn around time = %f\n",avgtat/n);
    printf("Average waiting time = %f\n",avgwt/n);
    
    printf("\nGantt Chart:\n");
    printf(" ");
    for(int i=0; i<time_index; i++) printf("____");
    printf("\n|");
    for(int i=0; i<time_index; i++){
        printf(" P%d |", timeline[i]);
    }
    printf("\n ");
    for(int i=0; i<time_index; i++) printf("----");
    printf("\n");
    printf("0");
    for(int i=1; i<=time_index; i++){
        printf("    %d", i);
    }
    printf("\n");
}
