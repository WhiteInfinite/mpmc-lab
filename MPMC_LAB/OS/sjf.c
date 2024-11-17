#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct process{
    int atime;
    int btime;
    int ctime;
    int wtime;
    int ttime;
    int pid;
    int completed;
}pr;
pr p[10]; 
int main(){
    int i,n,totwtime,totttime;
    printf("Enter the no. of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the atime & btime of pid: %d\n",i);
        scanf("%d %d",&p[i].atime,&p[i].btime);
        p[i].pid=i;
        p[i].completed=0;
    }
    int completed_process=0;
    int current_time=0;
    while(completed_process<n){
        int indx=-1,flag=0;
        int min_time=1000000;
        for(i=0;i<n;i++){
            if(p[i].completed == 0 && p[i].atime<=current_time && p[i].btime < min_time){
                min_time = p[i].btime;
                indx=i;
                flag=1;
            }
        }
        if(flag==1){
            p[indx].wtime=current_time-p[indx].atime;
            p[indx].ctime=current_time+p[indx].btime;
            p[indx].ttime=p[indx].ctime-p[indx].atime;
            current_time=p[indx].ctime;
            p[indx].completed=1;
            completed_process++;
        }
        else{
            current_time++;
        }
    }
    totttime=0;
    totwtime=0;
    for(i=0;i<n;i++){
        totttime=totttime+p[i].ttime;
        totwtime=totwtime+p[i].wtime;
    }
    float at,aw;
    at=totttime/n;
    aw=totwtime/n;
    printf("Average turnaround time is: %.2f\n",at);
    printf("Average waiting time is: %.2f\n\n",aw);
    printf("Gantt chart:\n");
    for(i=0;i<n;i++){
        printf("|P%d\t",p[i].pid);
    }
    printf("|\n%d",p[0].atime);
    for(i=0;i<n;i++){
        printf("  \t%d",p[i].ctime);
    }
}