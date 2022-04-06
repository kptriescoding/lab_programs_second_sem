#include<stdio.h>
int np,nf,pages[100];
int indexforlru(int frames[],int in){
int reti=0,p=in,flag=0;
for(int i=0;i<nf;i++){
    flag=0;
for(int j=in-1;j>-1;j--)
if(frames[i]==pages[j]){
    flag=1;
    if(p>j){
    reti=i;
    p=j;
    }
    break;
}
if(!flag)return i;
}
return reti;
}
int indexforlfu(int frames[],int in,int pt){
    int count[100];
    for(int i=0;i<in;i++)
    for(int j=0;j<nf;j++)
    if(frames[i]==pages[j])count[i]++;
    int min=count[pt],reti=pt;
    for(int i=0;i<nf;i++){
        if(min>count[i]){
            reti=i;
            min=count[i];
        }
    }
    return reti;
}
int indexforoptimal(int frames[],int in){
    int reti=0,p=in,flag=0;
for(int i=0;i<nf;i++){
    flag=0;
for(int j=in+1;j<np;j++)
if(frames[i]==pages[j]){
    flag=1;
    if(p<j){
    reti=i;
    p=j;
    }
    break;
}
if(!flag)return i;
}
return reti;
}
void replacement(int no){
    int frames[100],hit=0,pf=0,pt=-1;
    for(int i=0;i<nf;i++)frames[i]=-1;
    for(int i=0;i<np;i++){
        hit=0;
    for(int j=0;j<nf;j++)
        if(frames[j]==pages[i])hit=1;
        if(!hit){
            if(pf<nf){
               pt=(pt+1)%nf;
                printf("%d is added->1 faults\n",pages[i]);
                frames[pt]=pages[i];
            }
            else{
                if(no==1) pt=(pt+1)%nf;
               else if(no==2||no==4)pt=indexforlru(frames,i);
               else if (no==3)pt=indexforoptimal(frames,i);
                if(no==4)pt=indexforlfu(frames,i,pt);
                printf("%d replaces %d->1 pages fault\n",pages[i],frames[pt]);
                frames[pt]=pages[i];
            }
            pf++;
        }
        else
            printf("%d is present->0 pages fault\n",pages[i]);
    }
    printf("Pages fault is %d\n",pf);
}
int main(){
    printf("no of frames\n");
    scanf("%d",&nf);
    printf("no of pages\n");
    scanf("%d",&np);
    printf("enter pages\n");
    for(int i=0;i<np;i++)scanf("%d",&pages[i]);
    printf("fifo\n");
    replacement(1);
    printf("lru\n");
    replacement(2);
    printf("optimal\n");
    replacement(3);
    printf("lfu\n");
    replacement(4);
}