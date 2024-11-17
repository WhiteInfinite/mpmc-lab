#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    printf("Enter the no. of disks:\n");
    int n;
    scanf("%d",&n);
    int i;
    printf("Enter the disk requests:\n");
    int RQ[n];
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("\nEnter the head position:\n");
    int h;
    scanf("%d",&h);
    printf("\nMovevement direction is: (1 for high/0 for low)\n");
    int m;
    scanf("%d",&m);
    printf("Enter disk size:\n");
    int size;
    scanf("%d",&size);
    int j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++){
        if(RQ[i]>h){
            index=i;
            break;
        }
    }
    int totalmovement=0;
    if(m=0){
        for(i=index-1;i>=0;i--){
            totalmovement=totalmovement+abs(h-RQ[i]);
            h=RQ[i];
        }
        totalmovement=totalmovement+abs(RQ[0]-0);
        totalmovement=totalmovement+(size-2);
        h=size-1;
        for(i=n-1;i>=index;i--){
            totalmovement=totalmovement+abs(RQ[i]-h);
            h=RQ[i];
        }
    }
    else{
        for(i=index;i<n;i++){
            totalmovement=totalmovement+abs(RQ[i]-h);
            h=RQ[i];
        }
        totalmovement=totalmovement+abs(size-RQ[n-1]-1);
        totalmovement=totalmovement+(size-2);
        h=0;
        for(i=0;i<index;i++){
            totalmovement=totalmovement+abs(RQ[i]-h);
            h=RQ[i];
        }
    }
    printf("Total seeking time = %d\n",totalmovement);
}