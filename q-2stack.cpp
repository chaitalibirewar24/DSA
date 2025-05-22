#include<iostream>
#include<stack>
using namespace std;

class Oueue_stack
{
    private:
    stack<int> s1,s2;
    //stack<int> s2;
    public:
    void enqueue(int x)
    {
        //move from s2 to s1
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // push the new element in s1
        s1.push(x);
        //push back everything to s1
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int dequeue()
    {
        if(s1.empty())
        {
            cout<<"already empty";
            return -1;
        }
        else
        {
            int x=s1.top();
            s1.pop();
            return x;
        }
    }
};
//driver code

int main()
{
    Oueue_stack qs;
    qs.enqueue(2);
    qs.enqueue(3);
    qs.enqueue(4);
    qs.enqueue(5);
    cout<<qs.dequeue()<<endl;
    cout<<qs.dequeue()<<endl;
    cout<<qs.dequeue()<<endl;
    return 0;
}
