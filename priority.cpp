#include<iostream>
using namespace std;
int main()
{
    int burst_t[20], p[20], wait_t[20], turn_t[20], pr[20], i, j, n, total=0, pos, temp, avg_wt, avg_tt;
    cout<<"Enter Total Number of Process:";
    cin>>n;
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>burst_t[i];
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }	

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=burst_t[i];
        burst_t[i]=burst_t[pos];
        burst_t[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;            //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
            wait_t[i]+=burst_t[j];
        total+=wait_t[i];
    }
    avg_wt=total/n;      //average waiting time
    total=0;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turn_t[i]=burst_t[i]+wait_t[i];     //calculate turnaround time
        total+=turn_t[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<burst_t[i]<<"\t\t    "<<wait_t[i]<<"\t\t\t"<<turn_t[i];
    }
    avg_tt=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tt;
    return 0;
}

