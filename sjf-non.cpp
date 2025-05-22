//sjf

#include<iostream>
using namespace std;
class process
{
    public:
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int pid;
};
class sjf_non
{
    process *p;
    int n;
    public:
    sjf_non(int n)
    {
        this->n=n;
        p=new process[n];
    }
    ~sjf_non()
    {
        delete[]p;
    }
    void sort_process()
    {
        process temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(p[j].bt<p[i].bt)
                {
                 temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                }
                else {
                    if(p[j].bt==p[i].bt)
                    {
                        if(p[j].at<p[i].at)
                        {
                            temp=p[j];
                            p[j]=p[i];
                            p[i]=temp;
                        }
                    }
                    else
                    {
                    if(p[j].at==p[i].at)
                    {
                        if(p[j].pid<p[i].pid)
                        {
                            temp=p[j];
                            p[j]=p[i];
                            p[i]=temp;
                        }
                    }
                }
                }
                }
           
        }
       
    }
    void input()
    {
        for(int i=0;i<n;i++)
        {
            cout<<"arrival item for process "<<i<<endl;
            cin>>p[i].at;
            cout<<"Brust time for process "<<i<<endl;
            cin>>p[i].bt;
            p[i].pid = i + 1;
        }
    }
    void calculate_time()
    {
        sort_process();
        //ct of first process
        p[0].ct=p[0].at+p[0].bt;
        //wt of first process
        p[0].wt=0;
        //tat of first
        for (int i = 1; i < n; ++i) {
            p[i].ct=p[i-1].ct+p[i].bt;
        }
        for(int i=0;i<n;i++)
        {
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
        }
        
    }
    void display()
    {
        cout << "Process ID | Arrival Time | Burst Time |Completion Time| Waiting Time | Turnaround Time\n";
    cout << "---------------------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << "   P" << p[i].pid << "      |      " << p[i].at<<"       |      " << p[i].bt<<"      |      " << p[i].ct<<
             "        |      " << p[i].wt << "         |      " <<p[i].tat << endl;
    }
    }
   void gantt_chart()
   {
        cout<<"gantt chart:"<<endl;
        for (int i=0;i<n;++i)
        {
            cout<<" | p"<<p[i].pid<<" ";
        }
        cout<<" |\n";
        //time
        cout<<p[0].at;
        for (int i=0;i<n;++i)
        {
            cout<<"\t"<<p[i].ct;
        }cout<<endl;
    }
};
int main()
{
    
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    sjf_non sj(n);
    sj.input();
    sj.calculate_time();
    sj.display();
    sj.gantt_chart();

}