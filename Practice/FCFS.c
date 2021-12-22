#include<stdio.h>
int main()
{
    int bt[100],wt[100],ta[100],pr[100],pn[100],np,totta,totwt=0;
    float avgwt,avgta;
    printf("Enter the No of Processes\n");
    scanf("%d",&np);
    printf("Enter the burst time\n");
    for(int i=0;i<np;i++)
	{
  scanf("%d",&bt[i]);
  pn[i]=i+1;
	}
    printf("The sequence of processes is ");
for(int i=0;i<np;i++)
printf("P%d ",pn[i]);
wt[0]=0;
ta[0]=bt[0];
totta=bt[0];
for(int i=1;i<np;i++)
{
wt[i]=wt[i-1]+bt[i-1];
ta[i]=ta[i-1]+bt[i];
totta+=ta[i];
totwt+=wt[i];
}
printf("\n\n");
avgwt=((float)totwt)/(float)np;
avgta=((float)totta)/(float)np;
printf("%f %f",avgwt,avgta);
}
