#include<stdio.h>
int bl[100],mem[100],nb,nm,bln[100],blc[100];
void bubble_sort(){
for(int i=0;i<nb;i++)
for(int j=0;j<nb-i-1;j++)
{
if(blc[j]>blc[j+1]){
int temp=blc[j];
blc[j]=blc[j+1];
blc[j+1]=temp;
temp=bln[j];
bln[j]=bln[j+1];
bln[j+1]=temp;
}
}
}
void reset_block_array(){
for(int i=0;i<nb;i++){
blc[i]=bl[i];
bln[i]=i+1;
}
}
void worstfit(){
int f;
for(int i=0;i<nm;i++){
f=0;
bubble_sort();
int temp=blc[nb-1]-mem[i];
if(temp>=0)
{
f=1;
blc[nb-1]=temp;
}
if(!f)printf("%d\t\t%d\tNot Allocated\n",i+1,mem[i]);
else 
printf("%d\t\t%d\t\t%d\n",i+1,mem[i],bln[nb-1]);
}
}
void bestfit(){
int f,j;
for(int i=0;i<nm;i++){
f=0;
bubble_sort();
for(j=0;j<nb;j++){
int temp=blc[j]-mem[i];
if(temp>=0)
{
f=1;
blc[j]=temp;
break;
}
}
if(!f)printf("%d\t\t%d\tNot Allocated\n",i+1,mem[i]);
else
printf("%d\t\t%d\t\t%d\n",i+1,mem[i],bln[j]);
}
}
void firstfit(){
int t,id[100]={0},f,j;
for(int i=0;i<nm;i++){
f=0;
for(j=0;j<nb;j++){
int temp=blc[j]-mem[i];
if(temp>=0){
f=1;
blc[j]=temp;
break;
}
}
if(!f)printf("%d\t\t%d\tNot Allocated\n",i+1,mem[i]);
else
printf("%d\t\t%d\t\t%d\n",i+1,mem[i],bln[j]);
}
}
int main(){
printf("Enter the number of holes in memory\n");
scanf("%d",&nb);
printf("Enter the blocksize of each\n");
for(int i=0;i<nb;i++)
scanf("%d",&bl[i]);
printf("Enter the number of processes to which memory should be assigned\n");
scanf("%d",&nm);
printf("Enter the size of each\n");
for(int i=0;i<nm;i++)
scanf("%d",&mem[i]);
reset_block_array();
printf("\nWorst fit\nProcess no. Process size   Hole no.\n");
worstfit();
reset_block_array();
printf("\nBest fit\nProcess no. Process size   Hole no.\n");
bestfit();;
reset_block_array();
printf("\nFirst fit\nProcess no. Process size   Hole no.\n");
firstfit();
}
