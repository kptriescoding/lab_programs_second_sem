#include<stdio.h>
int checkrep(int f[],int i){
int flag=1;
for(int j=0;j<3;j++)
{
if(f[j]==i){
printf(" %d Already there->0 Page Faults\n",i);
flag=0;
return flag;
}
}
return flag;
}
int main(){
int f[3]={-1,-1,-1},pages[7]={1,3,0,3,5,6,3},np=7,nf=3,pf=0,pt=0;
for(int i=0;i<np;i++){
if(pf<nf){
int flag=checkrep(f,pages[i]);
if(flag==1){
f[pf++]=pages[i];
printf("Page %d is added to the frame->1 Page Fault\n",pages[i]);
}
}
else{
int flag=checkrep(f,pages[i]);
if(flag==1){
int temp=f[pt];
f[pt]=pages[i];
pt=(pt+1)%nf;
printf("Page %d replaced %d->1 Page Fault\n",pages[i],temp);
pf++;
}
}
}
printf(" %d\n",pf);
}
