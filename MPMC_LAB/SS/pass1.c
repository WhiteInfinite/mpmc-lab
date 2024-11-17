#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char label[10],operand[10],opcode[10],t1[10],t2[10],t3[10];
int s=-1,o=-1,size=0,i,opd;
int locctr,start,len,flag,ln;
FILE *f1,*f2,*f3,*f4,*f5;
struct OPTAB{
    char opcode[10];
    char hexcode[10]; 
}OT[30];
struct SYMTAB{
    char label[10];
    int addr;
}ST[30];
void read_OPTAB(){
    while(1){
        o++;
        fscanf(f2,"%s%s",OT[o].opcode,OT[o].hexcode);
        if(getc(f2)==EOF){
            break;
        }
    }
}
void read_line(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    fscanf(f1,"%s",t1);
    if(getc(f1)!='\n'){
        fscanf(f1,"%s",t2);
        if(getc(f1)!='\n'){
            fscanf(f1,"%s",t3);
        }
    }
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0){
        strcpy(label,t1);strcpy(opcode,t2);strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0){
        strcpy(label,"");strcpy(opcode,t1);strcpy(operand,t2);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")==0 && strcmp(t3,"")==0){
        strcpy(label,"");strcpy(opcode,t1);strcpy(operand,"");
    }
}

int main(){
    f1=fopen("input.txt","r");
    f2=fopen("opcode.txt","r");
    f3=fopen("symtab.txt","w");
    f4=fopen("intermediate.txt","w");
    f5=fopen("length.txt","w");
    read_OPTAB();

    fscanf(f1,"%s%s%x",label,opcode,&opd);
    if(strcmp(opcode,"START")==0){
        start=opd;
        locctr=start;
        fprintf(f4,"\t%s\t%s\t%x\n",label,opcode,opd);
        read_line();
    }
    else{
        locctr=0;
    }
    while(strcmp(opcode,"END")!=0){
        fprintf(f4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"")!=0){
            for(i=0;i<=s;i++){
                if(strcmp(ST[i].label,label)==0){
                    printf("Error");
                    exit(0);
                }
            }
            s++;
            strcpy(ST[s].label,label);
            ST[s].addr=locctr;
        }
        flag=0;
        for(i=0;i<=o;i++){
            if(strcmp(OT[i].opcode,opcode)==0){
                flag=1;
                locctr=locctr+0x3;
                size=size+3;
                break;
            }
        }
        if(flag==0){
            if(strcmp(opcode,"WORD")==0){
                locctr=locctr+0x3;
                size=size+3;
            }
            if(strcmp(opcode,"RESW")==0){
                locctr=locctr+(atoi(operand)*0x3);
            }
            if(strcmp(opcode,"RESB")==0){
                locctr=locctr+atoi(operand);
            }
            if(strcmp(opcode,"BYTE")==0){
                ln=strlen(operand);
                if(operand[0]=='c' || operand[0]=='C'){
                    ln=ln-3;
                }
                else{
                    ln=(ln-3)/2;
                }
                locctr=locctr+ln;
                size=size+ln;
            }
        }
        read_line();
    }
    fprintf(f4,"\t%s\t%s\t%s\n",label,opcode,operand);
    for(i=0;i<=s;i++){
        fprintf(f3,"%s\t%x",ST[i].label,ST[i].addr);
        if(i!=s){
            fprintf(f3,"\n");
        }
    }
    fprintf(f5,"%x\t%x",locctr-start,size);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
}