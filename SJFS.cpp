#include<stdio.h>
using namespace std;
int main()
{
    int burst_t[20],p[20],wait_t[20],turn_t[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tt;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_t[i]);
        p[i]=i+1;           //contains process number
    }
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_t[j]<burst_t[pos])
                pos=j;
        }
        temp=burst_t[i];
        burst_t[i]=burst_t[pos];
        burst_t[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wait_t[0]=0;            //waiting time for first process will be zero
 //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
            wait_t[i]+=burst_t[j];

        total+=wait_t[i];
    }
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn_t[i]=burst_t[i]+wait_t[i];     //calculate turnaround time
        total+=turn_t[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_t[i],wait_t[i],turn_t[i]);
    }
    avg_tt=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tt);
}

