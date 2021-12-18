#include<stdio.h>
int f[100],st,len;
void show_occupied(){
printf("Occupied Locations Are\n");
for(int i=0;i<100;i++){
if(f[i]!=-2)
printf(" %d->%d ",i,f[i]);
}
printf("\n");
}
void show_occupied_index(){
printf("Occupied Locations Are\n");
for(int i=0;i<100;i++){
if(f[i]!=-2)
printf(" %d->%d->0",f[i],i);
}
printf("\n");
}
void sequential(){
printf("Sequential allocation\n");
for(int i=0;i<100;i++)f[i]=-2;
int j=0;
while(j!=1){
int flag=0;
printf("Enter the starting block and the length of the block\n");
scanf("%d%d",&st,&len);
for(int i=st;i<(st+len);i++){
if(f[i]!=-2){
flag=1;
break;
}
}
if(!flag){
int prev=st;
for(int i=st+1;i<(st+len);i++){
f[prev]=i;
f[i]=-1;
prev=i;
}
printf("File allocated Successfully\n");
}
else
printf("File Not Allocated\n");
show_occupied();
printf("Enter 1 to quit any other number to continue\n");
scanf("%d",&j);
}
}
void linked_list(){
printf("Linked List allocation\n");
for(int i=0;i<100;i++)f[i]=-2;
int j=0,occ,n;
printf("How much blocks are already occupied\n");
scanf("%d",&n);
printf("Enter the already occupied blocks\n");
for(int i=0;i<n;i++){
scanf("%d",&occ);
f[occ]=0;
}
while(j!=1){
printf("Enter the starting block and the length of the block\n");
scanf("%d%d",&st,&len);
int i=st,count=0;
printf("Files allocated locations are\n");
if(f[st]==1)printf("Starting Block is Already Occupied\n");
else{
int prev=st;
while(count!=len){
if(f[i]==-2){
f[prev]=i;
f[i]=-1;
prev=i;
count++;
}
i++;
}
printf("File allocated Successfully\n");
}
show_occupied();
printf("Enter 1 to quit any other number to continue\n");
scanf("%d",&j);
}
}
void indexed_file(){
printf("Indexed file allocation\n");
for(int i=0;i<100;i++)f[i]=-2;
int j=0,ind,flag=0,indblk[100],ch=0;
while(j!=1){
printf("Enter the index block\n");
scanf("%d",&ind);
if(f[ind]==-2){
printf("Enter the length of the block\n");
scanf("%d",&len);
ch=0;
while(ch==0){
flag=0;
printf("Enter the blocks\n");
for(int i=0;i<len;i++){
scanf("%d",&indblk[i]);
if(f[indblk[i]]!=-2){
flag=1;
break;
}
}
if(!flag)
{
for(int i=0;i<len;i++)
f[indblk[i]]=ind;
printf("File allocated Successfully\n");
ch=1;
}
else 
printf("Block already Allocated Enter Values Again\n");
}
}
else
printf("Index Already Allocated\n");
show_occupied_index();
printf("Enter 1 to quit any other number to continue\n");
scanf("%d",&j);
}
}
int main(){
sequential();
linked_list();
indexed_file();
}
