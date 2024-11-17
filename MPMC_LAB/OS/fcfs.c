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
}pr;
pr p[10]; 
int main(){
    int i,j,n,totwtime,totttime;
    printf("Enter the no. of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the atime & btime of pid: %d\n",i);
        scanf("%d %d",&p[i].atime,&p[i].btime);
        p[i].pid=i;
    }
    pr temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].atime>p[j+1].atime){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp; 
            }
        }
    }
    p[0].wtime=0;
    p[0].ctime=p[0].btime+p[0].atime;
    p[0].ttime=p[0].ctime-p[0].atime;
    for(i=1;i<n;i++){
        if(p[i].atime<=p[i-1].ctime){
            p[i].wtime=p[i-1].ctime-p[i].atime;
            p[i].ctime=p[i-1].ctime+p[i].btime;
            p[i].ttime=p[i].ctime-p[i].atime;
        }
        else{
            p[i].wtime=0;
            p[i].ctime=p[i].atime+p[i].btime;
            p[i].ttime=p[i].ctime-p[i].atime;
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