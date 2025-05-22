//fcfs

#include<iostream>
using namespace std;
class Process
{
    public:
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    Process()
    {
         ct=0;
         tat=0;
         wt=0;
    }
};
class FCFS
{
    Process *p;
    int n;
    public:
    FCFS(int n)
    {
        this->n=n;
        p=new Process[n];
    }
    ~FCFS()
    {
        delete[]p;
    }
    void input()
    {
        for(int i=0;i<n;i++)
        {
            cout<<"arrival tiem for process "<<i<<endl;
            cin>>p[i].at;
            cout<<"Brust time for process "<<i<<endl;
            cin>>p[i].bt;
        }
    }
    void calculateTime()
    {
        
            //1st process has zero waiting time
            p[0].wt=0;
            //1st process tat 
            p[0].tat=p[0].bt;
           // 1st process ct
           p[0].ct=p[0].bt;
           for(int i=1;i<n;i++)
            {
                p[i].ct=p[i-1].ct+p[i].bt;
                p[i].tat=p[i].ct-p[i].at;
                p[i].wt=p[i].tat-p[i].bt;
            }
    }
    void display()
    {
        cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
        for (int i = 0; i < n; i++) {
            cout << i << "\t\t"
                 << p[i].at << "\t\t"
                 << p[i].bt << "\t\t"
                 << p[i].wt << "\t\t"
                 << p[i].tat << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    FCFS s(n);
    s.input();
    s.calculateTime();
    s.display();
    return 0;
}
