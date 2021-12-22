#include<stdio.h>
int f[100];
int main(){
int st,len,flag=0;
for(int i=0;i<100;i++)f[i]=-2;
while(1){
flag=0;
scanf("%d%d",&st,&len);
int prev=st;
for(int i=st;i<st+len;i++)
if(f[i]!=-2){
flag=1;
break;
}
if(flag)printf("Not\n");
else {
for(int i=st;i<st+len;i++){
f[prev]=i;
f[i]=-1;
prev=i;
}
printf("Allocated locations are\n");
for(int i=0;i<100;i++)if(f[i]!=-2)printf(" %d->%d ",i,f[i]);
}
}}

