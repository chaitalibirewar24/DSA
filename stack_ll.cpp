#include<iostream>
using namespace std;
class LL
{
    public:
    int size;
    class Node
    {
        public:
        string data;
        Node *next;
        Node(string data)
        {
            this->data=data;
        }
    };
    public:
    Node *head;
    public:
    LL()
    {
        this->size=0;
        this->head=NULL;
    }
    void push(string data)
    {
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            head->next=NULL;
        }
       
        else{
            Node* currnode=head;
            while(currnode->next!=NULL)
            {currnode=currnode->next;}
            currnode->next=newnode;
            newnode->next=NULL;
            
        }
        size++;
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        if (head->next == nullptr) { 
            // If only one node is present
            delete head;
            head = nullptr;
            size--;
            return;
        }
       else
       {
        Node *currnode=head;
        Node *prev=nullptr;
        while(currnode->next!=NULL)
        {
            prev=currnode;
            currnode=currnode->next;
        } 
        prev->next=NULL;
        cout<<"poped element="<<currnode->data<<endl;
        delete currnode;
        size--;
       }
    }
    void display()
    {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node * currnode=head;
       /* do
        {
           if(currnode->next!=NULL)
           {currnode=currnode->next;}
           cout<<currnode<<" ";
        } while (currnode!=head);  */
        while (currnode != nullptr) {
            cout << currnode->data << " ";
            currnode = currnode->next;
        }cout<<endl;
    }
    int getsize(){
        return size;
    }
};

int main()
{
    LL list;
    list.push("my");
    list.push("name");
    list.push("is");
    list.display();
    cout<<list.getsize()<<endl;
   list.pop();
   cout<<list.getsize()<<endl;
   // list.display();
    return 0;
}