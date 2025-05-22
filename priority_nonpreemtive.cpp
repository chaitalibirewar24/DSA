//priority_nonprimitive

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
    int prior;
    Process()
    {
         ct=0;
         tat=0;
         wt=0;
    }
};
class priority
{
    Process *p;
    int n;
    public:
    priority(int n)
    {
        this->n=n;
        p=new Process[n];
    }
    ~priority()
    {
        delete[]p;
    }
    void input()
    {
        for(int i=0;i<n;i++)
        {
            cout<<"arrival item for process "<<i<<endl;
            cin>>p[i].at;
            cout<<"Brust time for process "<<i<<endl;
            cin>>p[i].bt;
            cout<<"Priority of the  process "<<i<<endl;
            cin>>p[i].prior;
        }
    }
    void sort_process()
    {
        
        Process  temp;
        for (int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(p[i].prior<p[j].prior)
                {temp= p[i];
                p[i]=p[j];
                p[j]=temp;}
            }
        }
    }

    void calculateTime()
    {
        sort_process();
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
            
         }  
    }
    void display()
    {
        float awt = 0;  // Accumulated Waiting Time

        // Calculate Waiting Time (Wt) for each process
        for (int i = 0; i < n; i++) {
            p[i].wt = p[i].tat - p[i].bt; // Waiting time = Turnaround Time - Burst Time
            awt += p[i].wt;  // Add to the total waiting time
        }
        cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
        for (int i = 0; i < n; i++) {
            cout << i << "\t\t"
                 << p[i].at << "\t\t"
                 << p[i].bt << "\t\t"
                 << p[i].wt << "\t\t"
                 << p[i].tat << endl;
        }
        // Calculate and display average waiting time
        cout << "Average waiting time: " << awt / n << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    priority s(n);
    s.input();
    s.calculateTime();
    s.display();
    return 0;
}
 