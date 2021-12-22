#include<stdio.h>
int main(){
int n=5,m=3,need[100][100],count=0,ans[100],i,j,f[100]={0},max[100][100],alloc[100][100],avail[100];
/* int max[5][3] = { { 7, 5, 3 },
                   { 3, 2, 2 }, 
                   { 9, 0, 2 }, 
                   { 2, 2, 2 }, 
                   { 4, 3, 3 } };
int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
                     { 2, 0, 0 }, // P1
                     { 3, 0, 2 }, // P2
                     { 2, 1, 1 }, // P3
                     { 0, 0, 2 } }; // P4
                      int avail[3] = { 3, 3, 2 }; */
printf("Process\n");
scanf("%d",&n);
printf("Resource\n");
scanf("%d",&m);
printf("Max\n");
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
scanf("%d",&max[i][j]);
printf("Alloc\n");
for(int i=0;i<n;i++)
for(int j=0;j<m;j++){
scanf("%d",&alloc[i][j]);
need[i][j]=max[i][j]-alloc[i][j];
}

printf("Avail\n");
for(int j=0;j<m;j++)
scanf("%d",&avail[j]);
for(int k=0;k<n;k++){
for(int i=0;i<n;i++){
if(f[i]==0){
int flag=0;
for(int j=0;j<m;j++){
if(need[i][j]>avail[j]){
flag=1;
break;
}
}
if(flag==0){
for(int j=0;j<m;j++)
avail[j]+=alloc[i][j];//Important
ans[count++]=i;
f[i]=1;
}
}
}
}
//if(count!=n)printf("Not Safe\n");
//else 
for(int i=0;i<n;i++)printf(" P%d ",ans[i]);
}
