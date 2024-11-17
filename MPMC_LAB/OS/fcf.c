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
    int totalmovement=0;
    for(i=0;i<n;i++){
        totalmovement=totalmovement+abs(h-RQ[i]);
        h=RQ[i];
    }
    printf("Total seeking time = %d\n",totalmovement);
}