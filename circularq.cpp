#include<iostream>
using namespace std;
class Cqueue
{
    private:
    int max=6;
    int queue[6];
    int rear;
    int front;
    public:
    Cqueue()
    {rear=front=0;}
    bool isfull()
    {
        if(rear==max-1 && front==0)
        {return true;}
        if(front==(rear+1)%max)
        {return true;}
        return false;
    }
    bool isempty()
    {
        if(rear==0 && front==0)
        {return true;}
    }
    int add(int x)
    {
        if(isfull())
        {cout<<"already full"<<endl;}
        else
        {
            queue[rear]=x;
            cout<<"inserted element="<<queue[rear]<<endl;
            rear=(rear+1)%max;
        }
        return rear;
    }
    int remove()
    {
        //if(isempty())
        //{cout<<"already empty"<<endl;}
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Deleted element = " << queue[front] << endl;

        if (rear == front) {
            rear = 0;
            front = 0;
        }
        else
        {
            cout<<"deleted element="<<queue[front]<<endl;
            front=(front+1)%max;
        }
        return front;
    }
    bool peek()
    {
        return queue[front];
    }
    int display()
    {
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % max;
        }
        cout << endl;
    }
    
};
int main()
{
    //Queue q = new Queue(5);
    Cqueue q;
    q.add(2);
    q.add(10);
    q.add(40);
    q.add(30);
    q.add(20);
    q.add(50);
    q.remove();
    q.remove();
    q.remove();
    q.add(12);
    q.add(2);
    q.add(10);
    q.add(40);
    q.display();
    //q.add(40);
    //q.add(30);
    //q.add(20);
   // q.add(50);
}