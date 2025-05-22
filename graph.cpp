//Graphs:BFS and DFS

#include<iostream>
using namespace std;
const int max_size=100;

//simple queue
class Queue{
    public:
    int rear;
    int front;
    int queue[max_size];
    public:
    Queue()
    {
        this->rear=-1;
        this->front=-1;
    }
    bool isfull()
    {
      return rear==max_size-1;
    }
    bool isempty()
    {
        return front>rear || front==-1;
    }
    void enqueue(int value)
    {
        if(isfull())
        {
            cout<<"full"<<endl;
            return;
        }
        else{
            if(front==-1)
            {
                front=0;
            }
            queue[++rear]=value;
        }
    }
    int dequeue()
    {
        if(isempty())
        {
            cout<<"already empty"<<endl;
            return -1;
        }
        else{
           return queue[front++];
        }
    }
};


class graph{
    public:
    int v;
    
    class Node{
       
        public:
        int dest;
        Node *next;
        public:
        Node(int dest)
        {
            
            this->dest=dest;
            this->next=NULL;
        }
   
    };
    public:
    Node * list[max_size];
    graph(int v)
    {
        this->v=v;
        for(int i=0;i<v;i++)
        {
            list[i]=nullptr;
        }
    }
    void add(int s,int dest)//addedge
    {
        Node *newnode=new Node(dest);
        newnode->next=list[s];    
        list[s]=newnode;
    }
    void print()
    {
        for (int i=0;i<v;i++)
        {
            cout<<"Vertex "<< i<<":";
            Node *temp=list[i];
            while(temp)
            {
                cout<<"->"<<temp->dest;
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void BFS(int start)
    {
        Queue q;
        bool visit[v]={false};
        q.enqueue(start);
        while(!q.isempty())
        {
            int current=q.dequeue();
            if(!visit[current])
            {
                cout<<current<<" ";
                visit[current]=true;
                //adding neighbours
                Node *temp=list[current];
                while(temp!=NULL)
                {
                    q.enqueue(temp->dest);
                    temp=temp->next;  
                }
               
            }
        }

    }

    //DFS -> recursive function
    void DFS(int start,bool visit[])
    {
        int current=start;
        visit[current]=true;
        cout<<current<<" ";
         Node *temp=list[current];
         while(temp!=NULL)
         {
        if(!visit[temp->dest])
        {
            DFS(temp->dest,visit);
        }
        temp=temp->next;
        }
    }
    void dfs(int start)
    {
        bool visit[v]={false};
        DFS(start,visit);
    }
};

int main()
{
    graph g(5);         // Graph with 5 vertices: 0 to 4
    g.add(0, 1);   
    g.add(4, 1);   
    g.add(2, 4);   
    g.add(1, 3);  
    g.add(3,2); 
    g.add(3,1);
    g.print();
    cout<<"BFS traversal:";
    g.BFS(0);
    cout<<endl;
    cout<<"DFS traversal:";
    g.dfs(0);
    return 0;
}