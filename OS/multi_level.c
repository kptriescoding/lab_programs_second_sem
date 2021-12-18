#include<stdio.h>
struct process
{
    int p[100],pn[100],tot,pr[100];
float avg;
};
struct Process{
        int np;
struct process bt,wt,ta;
};
struct Process end(struct Process pro){
printf("The sequence of processes is ");
for(int i=0;i<pro.np;i++)
printf("P%d ",pro.bt.pn[i]);
pro.wt.p[0]=0;
pro.wt.tot=0;
for(int i=1;i<pro.np;i++)
{
pro.wt.p[i]=pro.wt.p[i-1]+pro.bt.p[i-1];
pro.wt.tot+=pro.wt.p[i];
}
pro.wt.avg=((float)pro.wt.tot)/(float)pro.np;
pro.bt.avg=((float)pro.bt.tot)/(float)pro.np;
pro.ta.avg=pro.bt.avg+pro.wt.avg;
printf("\nThe Average Waiting time for System Process is %.2f\n",pro.wt.avg);
printf("The Average Turn Around time for System Process is %.2f\n",pro.ta.avg);
return pro;
}
int main()
{
    float avgwt,avgta;
struct Process usepr,syspr;
//Input System Processes
syspr.wt.tot=0;
printf("Enter the number of System processes\n");
scanf("%d",&syspr.np);
printf("Enter the System processes\n");
for(int i=0;i<syspr.np;i++)
{
scanf("%d",&syspr.bt.p[i]);
syspr.bt.pn[i]=i+1;
syspr.bt.tot+=syspr.bt.p[i];
}
printf("Enter the System processes priority\n");
for(int i=0;i<syspr.np;i++)
scanf("%d",&syspr.bt.pr[i]);
//Input User Processes
printf("Enter the number of User processes\n");
scanf("%d",&usepr.np);
printf("Enter the User processes\n");
for(int i=0;i<usepr.np;i++)
{
scanf("%d",&usepr.bt.p[i]);
usepr.bt.pn[i]=syspr.np+i+1;
usepr.bt.tot+=usepr.bt.p[i];
}
//Sorting for System Processes
printf("The Sorting Algorithm Used for System processes is Priority\n");
for(int i=0;i<syspr.np;i++)
for(int j=0;j<syspr.np-i-1;j++)
{
if(syspr.bt.pr[j]>syspr.bt.pr[j+1])
{
int temp;
temp=syspr.bt.p[j];
syspr.bt.p[j]=syspr.bt.p[j+1];
syspr.bt.p[j+1]=temp;
temp=syspr.bt.pr[j];
syspr.bt.pr[j]=syspr.bt.pr[j+1];
syspr.bt.pr[j+1]=temp;
temp=syspr.bt.pn[j];
syspr.bt.pn[j]=syspr.bt.pn[j+1];
syspr.bt.pn[j+1]=temp;
}
}
syspr=end(syspr);
//Sorting for User Process
printf("The Sorting Algorithm Used for User processes is FCFS\n");
usepr=end(usepr);
avgwt=(usepr.wt.avg+syspr.wt.avg)/2.0;
avgta=(usepr.ta.avg+syspr.ta.avg)/2.0;
printf("\nThe Average Waiting time for Total Process is %.2f\n",avgwt);
printf("The Average Turn Around time for Total Process is %.2f\n",avgta);
}
