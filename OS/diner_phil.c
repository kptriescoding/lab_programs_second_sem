#include<stdio.h>
#include<stdlib.h>
int *forkavail,tph,comph=0;
struct philo{
int left,right;
}*phil;
void philosopher(int i){
if(phil[i].left==0){
if(i==tph-1){
if(forkavail[i-1]==0){
forkavail[i-1]=phil[i].left=1;
printf("Fork %d taken by Philosopher %d\n",i,i+1);
}
else
printf("Philosopher %d is waiting for fork %d\n",i+1,i);
}
else{
if(forkavail[i]==0){
forkavail[i]=phil[i].left=1;
printf("Fork %d taken by Philosopher %d\n",i+1,i+1);
}
else
printf("Philosopher %d is waiting for fork %d\n",i+1,i+1);
}
}
else if(phil[i].left==1&&phil[i].right==0){
if(i==tph-1){
if(forkavail[i]==0){
forkavail[i]=phil[i].right=1;
printf("Fork %d taken by Philosopher %d\n",i+1,i+1);
}
else
printf("Philosopher %d is waiting for fork %d\n",i+1,i+1);
}
else{
int tmp=i;
i-=1;
if(i==-1)i=tph-1;
if(forkavail[i]==0){
forkavail[i]=phil[tmp].right=1;
printf("Fork %d taken by Philosopher %d\n",i+1,tmp+1);
}
else
printf("Philosopher %d is waiting for fork %d\n",tmp+1,i+1);
}
}
else if(phil[i].left==1&&phil[i].right==1){
printf("Philsopher %d has finished eating\n",i+1);
int tmp=i-1;
if(tmp==-1)tmp=tph-1;
forkavail[i]=forkavail[tmp]=0;
printf("He has kept down the fork %d and %d\n",i+1,tmp+1);
phil[i].right=phil[i].left=2;
comph++;
}
else if(phil[i].left==2&&phil[i].right==2)
printf("Philsopher %d has finished eating\n",i+1);
}
int main(){
printf("Enter the number of philosophers\n");
scanf("%d",&tph);
phil=(struct philo*)malloc(tph*sizeof(struct philo));
forkavail=(int*)malloc(tph*sizeof(int));
for(int i=0;i<tph;i++)
{
forkavail[i]=0;
phil[i].right=0;
phil[i].left=0;
}
while(comph!=tph){
for(int i=0;i<tph;i++)
philosopher(i);
printf("Number of philosophers finished eating %d\n",comph);
}
}
