#include<stdio.h>
int bl[]={100,500,200,300,600},ps[]={212,417,112,426},nb=5,n=4,j;
int main(){
printf("Process No Process Size Block No\n");
for(int i=0;i<n;i++)
{
int flag=0;
for(j=0;j<nb;j++){
int temp=bl[j]-ps[i];
if(temp>=0){
flag=1;
bl[j]=temp;
break;
}
}
if(flag)printf("%d\t\t%d\t\t%d\n",i+1,ps[i],j+1);
else
printf("%d\t\t%d\t\tNA\n",i+1,ps[i]);
}
}
