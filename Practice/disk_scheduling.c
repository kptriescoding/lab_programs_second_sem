#include<stdio.h>
int disq[]={82,170,43,140,24,16,190};
int head=50,seektime;
int n=7;
int diff(int a,int b){
if(a>b)return a-b; else return sb-a;
}
int main(){
seektime=0;
for(int i=0;i<n;i++){
int temp=diff(head,disq[i]);
if(temp>=0){
printf("Head is moved from %d to %d\n",head,disq[i]);
seektime+=temp;head=disq[i];
}
}
printf("\n%d",seektime);
}
