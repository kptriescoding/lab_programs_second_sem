#include<stdio.h>
int in[100],nf,n,pfn;
int checkrep(int temp[],int i){
int flag=0;
for(int j=0;j<nf;j++){
                if(temp[j]==in[i]){
                    printf("Pages %d is already there -> 0 Page Faults\n",temp[j]);
                    flag=1;
                    break;
                }
                }
      return flag;     
}
int indexforlru(int index,int temp[]){
int ret_i=0,p=index;
for(int i=0;i<nf;i++){
for(int j=p-1;j>=0;j--){
if(temp[i]==in[j])
{
ret_i=i;
p=j;
break;
}
}
}
return ret_i;
}
int indexforoptimal(int index,int temp[]){
int ret_i=0,p=index,flag=0;
for(int i=0;i<nf;i++){
flag=0;
for(int j=p+1;j<n;j++){
if(temp[i]==in[j])
{
flag=1;
ret_i=i;
p=j;
break;
}
}
if(!flag) return i;
}
return ret_i;
}
int indexforlfu(int count[]){
int min_i,i,min;
for(int i=0;i<n;i++){
if(count[i]!=0){
min=count[i];
min_i=i;
break;
}
}
for(i=0;i<n;i++){
if(min>count[i]&&count[i]!=0){
min=count[i];
min_i=i;
}
}
count[min_i]--;
return min_i;
}
void start(int temp[],int i){
            int flag =0;
            flag=checkrep(temp,i);
                if(!flag){
            temp[pfn++]=in[i];
            if(pfn==nf){
                printf("Pages ");
                for(int j=0;j<nf;j++)printf(" %d ",temp[j]);
                printf("are allocated in empty slots -> %d Pages faults\n",pfn);
            }
                }
}
void fifo(){
    pfn=0;
    int temp[100],pt=0;
    for(int i=0;i<nf;i++)temp[i]=-1;
    for(int i=0;i<n;i++){
        if(pfn<nf)start(temp,i);
        else{
            int flag =0;
            flag=checkrep(temp,i);
                if(!flag){
                    int var=temp[pt];
                    temp[pt]=in[i];
                    printf("Pages %d has replaced oldest slot %d-> 1 Page Fault\n",temp[pt],var);
                    pfn++;
                     pt=(pt+1)%nf;
                }
        }
    }
    printf("The number of page faults is %d\n",pfn);
}
void lru(){
pfn=0;
int temp[100],pt=0,inpt=0,cpy[100];
for(int i=0;i<n;i++){
temp[i]=-1;
cpy[i]=in[i];
}
for(int i=0;i<n;i++){
if(pfn<nf)start(temp,i);
else{
int flag=0;
flag=checkrep(temp,i);
if(!flag){
pt=indexforlru(i,temp);
int var=temp[pt];
temp[pt]=in[i];
printf("Pages %d has replaced recently used slot %d-> 1 Page Fault\n",temp[pt],var);
pfn++;
}
}
}
}
void lfu(){
pfn=0;
int temp[100],pt=0,count[100],j=0;
for(int i=0;i<n;i++){temp[i]=-1,count[i]=0;};
for(int i=0;i<n;i++){
if(pfn<nf){
start(temp,i);
count[in[i]]++;
}
else{
int flag=0;
for(int j=0;j<nf;j++){
                if(temp[j]==in[i]){
                    printf("Pages %d is already there -> 0 Page Faults\n",temp[j]);
                    count[temp[j]]++;
                    flag=1;
                    break;
                }
                }
if(!flag){
pt=indexforlfu(count);
int var=temp[pt];
temp[pt]=in[i];
printf("Pages %d has replaced least freqeuntly slot %d-> 1 Page Fault\n",temp[pt],var);
pfn++;
}
}
}
printf("The number of page faults is %d\n",pfn);
}
void optimal(){
pfn=0;
int temp[100],pt=0,inpt=0,cpy[100];
for(int i=0;i<n;i++){
temp[i]=-1;
cpy[i]=in[i];
}
for(int i=0;i<n;i++){
if(pfn<nf)start(temp,i);
else{
int flag=0;
flag=checkrep(temp,i);
if(!flag){
pt=indexforoptimal(i,temp);
int var=temp[pt];
temp[pt]=in[i];
printf("Pages %d has replaced optimal used slot %d-> 1 Page Fault\n",temp[pt],var);
pfn++;
}
}
}
printf("The number of page faults is %d\n",pfn);
}
int main(){
printf("Enter the number of frames\n");
scanf("%d",&nf);
printf("Enter the number of pages for in the sequence queue\n");
scanf("%d",&n);
printf("Enter the sequence\n");
for(int i=0;i<n;i++)
scanf("%d",&in[i]);
fifo();
lru();
lfu();
optimal();
}

