#include<stdio.h>
typedef struct Process{
int p[100],pn[100],pr[100],tot;
float avg;
} process;
int np=4,q=5;
process bt,wt,ta;
void process_sequence(process bt){
printf("The sequence of processes is ");
for(int i=0;i<np;i++)
printf("P%d ",bt.pn[i]);
}
int min(int* a,int b){
if(*a<=b){int temp=*a;
*a=0; 
return temp;}
else{*a-=b;
     return b;
     }
}
void end(process bt,process wt){
wt.avg=((float)wt.tot)/(float)np;
bt.avg=((float)bt.tot)/(float)np;
ta.avg=wt.avg+bt.avg;
printf("\nThe Average Waiting time is %.2f\n",wt.avg);
printf("The Average Turn Around time is %.2f\n",ta.avg);
}
process sorting(process bt){
for(int i=0;i<np;i++)
for(int j=0;j<np-i-1;j++)
{
if(bt.pr[j]>bt.pr[j+1])
{
int temp;
temp=bt.p[j];
bt.p[j]=bt.p[j+1];
bt.p[j+1]=temp;
temp=bt.pn[j];
bt.pn[j]=bt.pn[j+1];
bt.pn[j+1]=temp;
temp=bt.pr[j];
bt.pr[j]=bt.pr[j+1];
bt.pr[j+1]=temp;
}
}
return bt;
}
process waiting_time(process bt,process wt){
wt.p[0]=0;
for(int i=1;i<np;i++)
{
wt.p[i]=wt.p[i-1]+bt.p[i-1];
wt.tot+=wt.p[i];
}
return wt;
}
void fcfs(process bt,process wt){
printf("The Sorting Algorithm Used is FCFS\n");
wt=waiting_time(bt,wt);
process_sequence(bt);
end(bt,wt);
}
void sjf(process bt,process wt){
printf("The Sorting Algorithm Used is SJF\n");
for(int i=0;i<np;i++)
bt.pr[i]=bt.p[i];
bt=sorting(bt);
wt=waiting_time(bt,wt);
process_sequence(bt);
end(bt,wt);
}
void priority(process bt,process wt){
printf("The Sorting Algorithm Used is Priority\n");
bt=sorting(bt);
wt=waiting_time(bt,wt);
process_sequence(bt);
end(bt,wt);
}
void round_robin(process bt,process wt){
int tt,tp[100];
for(int i=0;i<np;i++)
tp[i]=0;
printf("The Sorting Algorithm Used is Round Robin\n");
printf("The sequence of process is ");
while(bt.tot!=tt)
for(int i=0;i<np;i++)
{
if(bt.p[i]!=0)
{
wt.p[i]=wt.p[i]+tt-tp[i];
tt+=min(&bt.p[i],q);
tp[i]=tt;
printf(" P%d ",i+1);
}
}
for(int i=0;i<np;i++)
wt.tot+=wt.p[i];
end(bt,wt);
}
int main()
{
wt.tot=0;
bt.tot=0;
printf("Enter the number of processes\n");
scanf("%d",&np);
printf("Enter the processes\n");
for(int i=0;i<np;i++){
scanf("%d",&bt.p[i]);
bt.tot+=bt.p[i];
bt.pn[i]=i+1;
wt.p[i]=0;
wt.pr[i]=0;
}

printf("Enter the priority of each process(for priority)\n");
for(int i=0;i<np;i++)
scanf("%d",&bt.pr[i]);
printf("Enter the quantum time for round robin\n");
scanf("%d",&q);
fcfs(bt,wt);
sjf(bt,wt);
priority(bt,wt);
round_robin(bt,wt);
}
