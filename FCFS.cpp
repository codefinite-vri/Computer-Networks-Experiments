#include<iostream>
using namespace std;
int main()
{
    int n,burst_t[20],wait_t[20],turn_t[20],avgwt=0,avgtt=0,i,j;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>burst_t[i];
    }

    wait_t[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
            wait_t[i]+=burst_t[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        turn_t[i]=burst_t[i]+wait_t[i];
        avgwt+=wait_t[i];
        avgtt+=turn_t[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<burst_t[i]<<"\t\t"<<wait_t[i]<<"\t\t"<<turn_t[i];
    }

    avgwt/=i;
    avgtt/=i;
    cout<<"\n\nAverage Waiting Time:"<<avgwt;
    cout<<"\nAverage Turnaround Time:"<<avgtt;
    return 0;
}

