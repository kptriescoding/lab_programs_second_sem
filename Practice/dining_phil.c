#include<stdio.h>
int forkavail[5],n=5,count=0;
struct{
int left,right;
}phil[5];
int main(){
int i=0;
for(int i=0;i<n;i++)
phil[i].right=phil[i].left=forkavail[i]=0;
while(count!=n){
for(int i=0;i<n;i++){
if(phil[i].left==0){
if(i==n-1){
if(forkavail[i-1]==0)
{
printf(" %d took %d\n",i+1,i);
phil[i].left=forkavail[i-1]=1;
}
else
printf(" %d is Hungry\n",i+1);
}
else{
if(forkavail[i]==0)
{
printf(" %d took %d\n",i+1,i+1);
phil[i].left=forkavail[i]=1;
}
else
printf(" %d is Hungry\n",i+1);
}
}
else if(phil[i].left==1&&phil[i].right==0){
if(i==n-1){
if(forkavail[i]==0)
{
printf(" %d took %d\n",i+1,i+1);
phil[i].right=forkavail[i]=1;
}
else
printf(" %d is Hungry\n",i+1);
}
else{
int temp=i-1;
if(temp==-1)temp=n-1;
if(forkavail[temp]==0)
{
printf(" %d took %d\n",i+1,temp+1);
phil[i].right=forkavail[temp]=1;
}
else
printf(" %d is Hungry\n",i+1);
}
}
else if(phil[i].left==1&&phil[i].right==1){
int temp=i-1;
if(temp==-1)temp=n-1;
printf(" %d finished\n",i+1);
printf("Kept down %d and %d",i+1,temp+1);
forkavail[i]=forkavail[temp]=0;
phil[i].left=phil[i].right=2;
printf(" %d finished\n",i+1);
count++;
}
else if(phil[i].left==2&&phil[i].right==2)
printf(" %d finished\n",i+1);
}
printf(" %d finished dinner\n",count);
}
}
