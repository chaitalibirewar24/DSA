/*#include<iostream>
#include<stack>
using namespace std;
int rev(const string& original)
{
    stack<char>ori;
    string reverse="";
    for(int i=0;original[i]!='\0';i++)
    {
       
        ori.push(original[i]);
        
    }
    while(!ori.empty())
    {
        reverse += ori.top();
        ori.pop();
    }
    cout<<"reverse:"<<reverse<<endl;
        if(original==reverse)
        {
            cout<<original<<" is palidrome";
        }
        else{cout<<original<<" is not palidrome";
        }
return 0;
}
int main()
{
    string original;
    cout<<"enter the string";
    getline(cin,original);
    rev(original);
    return 0;
}*/

//STACK REVERSE

#include<iostream>
#include<string>
using namespace std;
class Stack
{
    private:
    char *a;
    int n;
    int top;
    public:
    Stack(int size)
    {
        this->n=size;
        top=-1;
        a=new char[n];
    }
    bool isempty()
    {
        if(top==-1)
        {return true;}
        else
        return false;
    }
    bool isfull()
    {
        if(top==n-1)
        {return true;}
        else
        return false;
    }
    void push(char x)
    {
        if(isfull())
        {
            cout<<"overflow"<<endl;
        }
        a[++top]=x;

    }
    char pop()
    {
        if(isempty())
        {
            cout<<"already empty"<<endl;
        }
        char popval=a[top];
        a[top]=0;
        top--;
        return popval;
    }
    char peek()
    {
        if(isempty())
        {cout<<"already empty"<<endl;}
        else
        {
            return a[top];
        }
    }
    void display()
    {
        if(isempty())
        {cout<<"already empty"<<endl;}
        else
        {
            for(int i=top;i>=0;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }  
};
void reverse(string ori)
{
    int n=ori.length();
    Stack s(n);
    for(int i=0;i<n;i++)
    {
        s.push(ori[i]);
    }
    string reversed="";
    while(!s.isempty())
    {
        reversed+=s.pop();
    }
    cout<<reversed;

}
int main()
{
    string ori;
    cout<<"enter the string"<<endl;
    cin>>ori;
    cout<<ori<<endl;
    reverse(ori);
    return 0;
}