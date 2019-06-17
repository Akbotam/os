#include<stdio.h>

void main()
{
int bt[101],p[101],wt[101],n,total=0,pos,temp;
float avg_wt;
printf("Enter number of process:");
scanf("%d",&n);

printf("\nEnter Burst Time:\n");
for(int i=0;i<n;i++)
{
printf("p%d:",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}

//sorting by burst time
for(int i=0;i<n;i++)
{
pos=i;
for(int j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
pos=j;
}

temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;

temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}

wt[0]=0;

//calculate waiting time
for(int i=1;i<n;i++)
{
wt[i]=0;
for(int j=0;j<i;j++)
wt[i]+=bt[j];

total+=wt[i];
}

avg_wt=(float)total/n;
total=0;

printf("\nProcess\t Burst Time \tWaiting Time");
for(int i=0;i<n;i++)
{
printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i]);
}

printf("\n\nAverage Waiting Time=%f",avg_wt);
}
