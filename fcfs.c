#include<stdio.h>

int main()
{
    int n,bt[20],wt[20],avwt=0;
    printf("Enter the total number of processes");
    scanf("%d",&n);

    printf("\nEnter the Process Burst Time\n");
    for( int i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    for(int i=1;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
             avwt+=wt[i];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time");

    for(int i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i]);
    }

    avwt/=n;
    printf("\n\nAverage Waiting Time:%d",avwt);

    return 0;
}
