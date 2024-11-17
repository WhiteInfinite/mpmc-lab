#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n,m;
    printf("Enter the length of reference string:\n");
    scanf("%d",&n);
    printf("Enter the no. of frames:\n");
    scanf("%d",&m);
    int rs[n],f[m];
    int i,j,flag,pf=0,c=0;
    int k;
    printf("Enter the characters of reference string:\n");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    for(i=0;i<m;i++){
        f[i]=-1;
    }
    for(i=0;i<n;i++){
        flag = 0;
        for(j=0;j<m;j++){
            if(rs[i]==f[j]){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            f[c]=rs[i];
            c=(c+1)%m;
            pf++;
        }
        for(k=0;k<m;k++){
            printf("%d\t",f[k]);
        }
        if(flag==1){
            printf("Page hit\n");
        }
        else{
            printf("Page fault %d\n",pf);
        }
    }
}