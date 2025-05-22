#include<iostream>
using namespace std;

class Process {
public:
    int at;       // Arrival time
    int bt;       // Burst time
    int ct;       // Completion time
    int tat;      // Turnaround time
    int wt;       // Waiting time
    int pid;
    int rem_bt;   // Remaining burst time

    Process() {
        ct = 0;
        tat = 0;
        wt = 0;
        rem_bt = 0;
    }
};

class rr {
public:
    Process *p;   // Pointer to Process array
    int n;        // Number of processes
    int quantum;  // Time quantum

public:
    rr(int n, int quantum) {
        this->n = n;
        this->quantum = quantum;
        p = new Process[n];
    }

    ~rr() {
        delete[] p;
    }

    // Input function to get arrival and burst time for each process
    void input() {
        for (int i = 0; i < n; i++) {
            cout << "Arrival time for process " << i + 1 << ": ";
            cin >> p[i].at;
            cout << "Burst time for process " << i + 1 << ": ";
            cin >> p[i].bt;
            p[i].rem_bt = p[i].bt; // Initialize remaining burst time
            p[i].pid = i + 1; 
        }
    }

    // Round Robin Scheduling calculation
    /*void calculateTime() {
        int time = 0;      // Current time
        int count = 0;     // Number of completed processes
        bool allCompleted = false;

        // Keep looping until all processes are completed
        while (!allCompleted) {
            allCompleted = true;

            // Iterate over all processes
            for (int i = 0; i < n; i++) {
                if (p[i].rem_bt > 0) {
                    allCompleted = false; // If any process still has remaining burst time, keep looping

                    // If remaining burst time is greater than quantum, it runs for quantum time
                    if (p[i].rem_bt > quantum) {
                        time += quantum;
                        p[i].rem_bt -= quantum;
                    } else { // Otherwise, it runs for the remaining burst time
                        time += p[i].rem_bt;
                        p[i].ct = time;  // Set the completion time when the process completes
                        p[i].rem_bt = 0; // Process is completed
                    }

                    // Calculate Turnaround Time for each process
                    p[i].tat = p[i].ct - p[i].at;
                }
            }
        }
    }*/

    void calculateTime()
    {
        int count=0;
        int current=0;

        // Queue management: use an array to track ready processes (circular queue)
        int  rear=0;
        int  front=0;
        int *queue=new int[n];

        //all process in ready queue
        for(int i=0;i<n;i++)
        {
            queue[rear++]=i;
        }

        //execute the process in a round-robin
        while(count<n)
        {
            int i=queue[front]; //index of 1st process
            front=(front+1)%n; //move front to next position(circular queue)

            if(p[i].rem_bt>0)
            {
                // If the remaining burst time is greater than the quantum, execute for quantum time
                if(p[i].rem_bt>quantum)
                {
                    current=current+quantum;
                    p[i].rem_bt-=quantum;
                }
                // If the remaining burst time is less than or equal to quantum, complete the process
                else
                {
                    current+=p[i].rem_bt;
                    p[i].wt=current-p[i].at-p[i].bt;
                    p[i].tat = p[i].wt + p[i].bt;     
                    p[i].rem_bt = 0;  // Process is completed
                    count++;           // Increment the completed process count
                }
                if(p[i].rem_bt>0)
                {
                    queue[rear++]=i;
                }
            }

        }

    }

    // Display results
    void display() {
        int awt = 0;  // Accumulated Waiting Time

        // Calculate Waiting Time (Wt) for each process
        for (int i = 0; i < n; i++) {
            p[i].wt = p[i].tat - p[i].bt; // Waiting time = Turnaround Time - Burst Time
            awt += p[i].wt;  // Add to the total waiting time
        }

        // Display Process Information
        cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTaT\tWT" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << "\t"
                 << p[i].at << "\t"
                 << p[i].bt << "\t"
                 << p[i].ct << "\t"
                 << p[i].tat << "\t"
                 << p[i].wt << endl;
        }

        // Calculate and display average waiting time
        cout << "Average waiting time: " << (float)awt / n << endl;
    }
};

int main() {
    int n, quantum;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter quantum: ";
    cin >> quantum;

    rr r(n, quantum); // Create RR object with n processes and quantum
    r.input();         // Get input for each process
    r.calculateTime(); // Perform Round Robin scheduling and calculate times
    r.display();       // Display results

    return 0;
}
