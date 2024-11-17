#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char address[10],label[10],opcode[10],operand[10],t1[10],t2[10],t3[10],t4[10],a[10],ad[10],length[10],size[10],start[10];
int o=-1,s=-1;
int i,j;
FILE *f1,*f2,*f3,*f4,*f5,*f6;
struct SYMTAB{
    char label[10];
    char address[10];
}ST[30];
struct OPTAB{
    char opcode[10];
    char hexcode[10];
}OT[30];
void read_symtab(){
    while(1){
        s++;
        fscanf(f2,"%s%s",&ST[s].label,&ST[s].address);
        if(getc(f2)==EOF){
            break;
        }
    }
}
void read_optab(){
    while(1){
        o++;
        fscanf(f3,"%s%s",&OT[o].opcode,&OT[o].hexcode);
        if(getc(f3)==EOF){
            break;
        }
    }
}
void read_line(){
    strcpy(t1,"");strcpy(t2,"");strcpy(t3,"");strcpy(t4,"");
    fscanf(f1,"%s",t1);
    if(getc(f1)!='\n'){
        fscanf(f1,"%s",t2);
        if(getc(f1)!='\n'){
            fscanf(f1,"%s",t3);
            if(getc(f1)!='\n'){
                fscanf(f1,"%s",t4);
            }
        }
    }
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0 && strcmp(t4,"")!=0){
        strcpy(address,t1);strcpy(label,t2);strcpy(opcode,t3);strcpy(operand,t4);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0 && strcmp(t4,"")==0){
        strcpy(address,t1);strcpy(label,"");strcpy(opcode,t2);strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0 && strcmp(t4,"")==0){
        if(strcmp(t1,"END")==0){
            strcpy(address,"");strcpy(label,"");strcpy(opcode,t1);strcpy(operand,t2);
        }
        else{
            strcpy(address,t1);strcpy(label,"");strcpy(opcode,t2);strcpy(operand,"");
        }
    }
}

int main(){
    f1=fopen("intermediate.txt","r");
    f2=fopen("symtab.txt","r");
    f3=fopen("opcode.txt","r");
    f4=fopen("length.txt","r");
    f5=fopen("assembly_listing.txt","w");
    f6=fopen("object_code.txt","w");
    read_optab();
    read_symtab();
    fscanf(f4,"%s%s",length,size);
    fscanf(f1,"%s%s%s",label,opcode,operand);
    strcpy(start,operand);
    if(strcmp(opcode,"START")==0){
        fprintf(f5,"\t%s\t%s\t%s\n",label,opcode,operand);
        fprintf(f6,"H^%s^00%s^0000%s\n",label,operand,length);
        fprintf(f6,"T^00%s^%x",operand,atoi(size));
        read_line();
    }
    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"BYTE")==0){
            fprintf(f5,"%s\t%s\t%s\t%s\t",address,label,opcode,operand);
            sprintf(a,"%x",operand[2]);
            fprintf(f5,"%s\n",a);
            fprintf(f6,"^%s",a);
        }
        else if(strcmp(opcode,"WORD")==0){
            sprintf(ad,"%x",atoi(operand));
            fprintf(f5,"%s\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,ad);
            fprintf(f6,"^00000%s",ad);
        }
        else if(strcmp(opcode,"RESB")==0 || strcmp(opcode,"RESW")==0){
            fprintf(f5,"%s\t%s\t%s\t%s\n",address,label,opcode,operand);
        }
        else{
            for(i=0;i<=s;i++){
                if(strcmp(ST[i].label,operand)==0){
                    break;
                }
            }
            for(j=0;j<=o;j++){
                if(strcmp(OT[j].opcode,opcode)==0){
                    break;
                }
            }
            fprintf(f5,"%s\t%s\t%s\t%s\t%s%s\n",address,label,opcode,operand,OT[j].hexcode,ST[i].address);
            fprintf(f6,"^%s%s",OT[j].hexcode,ST[i].address);
        }
        read_line();
    }
    fprintf(f5,"\t%s\t%s\t%s\n",label,opcode,operand);
    fprintf(f6,"\nE^00%s",start);
}