#include<iostream>
using namespace std;
class Stack
{
    public:
    int max;
    int top;
    int *stack;
    public:
    Stack(int size)
    {
        max=size;
        stack=new int[size];
        top=-1;
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
       return top>max;
    }
    int push(int x)
    {
        
        if(isFull())
        {cout<<"overflow"<<endl;}
        else
        {stack[++top]=x;}
    }
    int pop()
    {
        
        if(isEmpty())
        {cout<<"already empty"<<endl;}
        else
        {
        cout<<"poped element is "<<stack[top]<<endl;    
        top--;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"empty";
        }
        else{
            return stack[top];
        }
    }
    void display()
    {
        if(top>=0)
        {
            cout<<"stack elements are:"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<endl;
            }
        }
       else
            {
                cout<<"stack is empty"<<endl;
            }
        
    }

};
int main()
{
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    Stack s(size);
    int choice;
   do
   {
    cout<<"enter choice 1.push   2. pop   3.display   4.Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"element want to insert"<<endl;
        int n;
        cin>>n;
        s.push(n);
        break;
    case 2:
        s.pop();
        break;
    case 3:
        s.display();
        break;
    case 4:
        cout<<"Exit"<<endl;
        break;
    default:
        cout<<"enter correct choice"<<endl;
        break;
    }
}while (choice!=4);
   return 0;
}