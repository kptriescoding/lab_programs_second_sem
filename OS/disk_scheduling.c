#include<stdio.h>
int diskque[100];
int n;
int head,seektime;
void print_array(int arr[]){
for(int i=0;i<n;i++)
printf(" %d ",arr[i]);
printf("\n");
}
int diff(int a,int b){
if(a>b)return a-b;
else return b-a;
}
 int mindiff(int arr[],int head){
int min=99999,minterm,mini;
for(int i=0;i<n;i++){
if(min>diff(arr[i],head)){
min=diff(arr[i],head);
minterm=arr[i];
mini=i;
}
}
arr[mini]=99999;
return minterm;
}
void bubble_sort(int arr[]){
for(int i=0;i<n;i++)
for(int j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}

}
void fcfs(){
seektime=0;
printf("FCFS Scheduling\n");
printf("Head Position is %d\n",head);
printf("Disk Queue is\n");
print_array(diskque); 
for(int i=0;i<n;i++)
{
printf("Head is moved from %d to %d\n",head,diskque[i]);
seektime+=diff(head,diskque[i]);
head=diskque[i];
}
printf("Seek Time is %d\n",seektime);
}
void sstf(){
seektime=0;
int temp[100];
printf("SSTF Scheduling\n");
printf("Head Position is %d\n",head);
printf("Disk Queue is\n");
print_array(diskque); 
for(int i=0;i<n;i++)
temp[i]=diskque[i];
for(int i=0;i<n;i++)
{
int dif=mindiff(temp,head);
printf("Head is moved from %d to %d\n",head,dif);
seektime+=diff(head,dif);
head=dif;
}
printf("Seek Time is %d\n",seektime);
}
void scan(){
seektime=0;
int temp[100];
printf("SCAN Scheduling\n");
printf("Head Position is %d\n",head);
printf("Disk Queue is\n");
print_array(diskque); 
printf("We are moving right first\n");
for(int i=0;i<n;i++)
temp[i]=diskque[i];
printf("What is the maximum size of the disk\n");
scanf("%d",&temp[n]);
bubble_sort(temp);
for(int i=0;i<n+1;i++)
{
if(head<=temp[i]){
printf("Head is moved from %d to %d\n",head,temp[i]);
seektime+=diff(head,temp[i]);
head=temp[i];
temp[i]=temp[n]+1;
}
}
for(int i=n;i>=0;i--)
{
if(head>temp[i]){
printf("Head is moved from %d to %d\n",head,temp[i]);
seektime+=diff(head,temp[i]);
head=temp[i];
}
}
printf("Seek Time is %d\n",seektime);
}
void c_scan(){
seektime=0;
int temp[100];
printf("SCAN Scheduling\n");
printf("Head Position is %d\n",head);
printf("Disk Queue is\n");
print_array(diskque); 
printf("We are moving right first\n");
for(int i=0;i<n;i++)
temp[i]=diskque[i];
printf("What is the maximum size of the disk\n");
scanf("%d",&temp[n]);
bubble_sort(temp);
for(int i=0;i<n+1;i++)
{
if(head<=temp[i]){
printf("Head is moved from %d to %d\n",head,temp[i]);
seektime+=diff(head,temp[i]);
head=temp[i];
temp[i]=temp[n]+1;
}
}
printf("Head is moved from %d to 0\n",head);
seektime+=head;
int a=head;
head=0;
for(int i=0;i<n;i++)
{
if(a>temp[i]){
printf("Head is moved from %d to %d\n",head,temp[i]);
seektime+=diff(head,temp[i]);
head=temp[i];
}
}
printf("Seek Time is %d\n",seektime);
}
int main(){
int in;
printf("Enter the number of cylinders\n");
scanf("%d",&n);
printf("Enter the work queue\n");
for(int i=0;i<n;i++)
scanf("%d",&diskque[i]);
printf("Enter the initial head position\n");
scanf("%d",&in);
head=in;
//fcfs();
head=in;
//sstf();
head=in;
//scan();
head=in;
c_scan();
}
