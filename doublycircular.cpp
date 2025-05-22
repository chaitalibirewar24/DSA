#include<iostream>
using namespace std;
class LL{
    public:
    int size;
    class Node{
        public:
        string data;
        Node* next;
        Node*prev;
        Node(string data)
        {
            this->next=NULL;
            this->prev=NULL;
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

    void addfirst(string data)
    {
        Node *newnode=new Node(data);
        if (head == NULL) {
            head = newnode;
            head->next = head;
            head->prev = head;
        }
        else{
        newnode->next=head;
        newnode->prev = head->prev;
        head->prev->next=newnode;
        head->prev=newnode;
        head=newnode;
        }
        size++;
    }
    void addlast(string data)
    {
        Node *lastnode;
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            head->next=newnode;
            head->next = head;
            head->prev = head;

        }
        else
        {
        lastnode=head->prev;
        lastnode->next=newnode;
        newnode->next=head;
        newnode->prev=lastnode;
        head->prev=lastnode;
        }
        size++;
    }
    void addpos(string data)
    {
        int pos;
        cout<<"enter the position"<<endl;
        cin>>pos;
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if(pos==1)
        {addfirst(data);}
        if (pos == size + 1) {
            addlast(data);
            return;}
        else
        {
            Node*currnode=head;
            Node *newnode=new Node(data);
            for(int i=1;i<pos-1;i++)
            {
                currnode=currnode->next;
            }
            
            Node *temp = currnode->next;
            newnode->next = temp;
            newnode->prev = currnode;
            currnode->next = newnode;
            temp->prev = newnode;

        }
        size++;
    }
    
    void deletefirst()
    {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // Only one node in the list
            delete head;
            head = NULL;
        } else {
            Node* lastnode = head->prev;
            Node* temp = head->next;
            lastnode->next=temp;
            temp->prev=lastnode;
            delete head;
            head=temp;
        }
        size--;
    }
    void deletelast()
    {
       
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* lastnode = head->prev;
        Node*temp;
        if (head == lastnode) {  // Only one node in the list
            delete head;
            head = NULL;
        } 
        else
        { 
            lastnode->prev->next = head;  // Update second last node's next pointer
            head->prev = lastnode->prev;  // Update head's prev pointer
            delete lastnode;  // Free last node   
        }
        size--;
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    int capacity()
    {return size;}
};
int main()
{
    LL list;
    list.addfirst("A");
    list.addfirst("B");
    list.addlast("C");
    list.addpos("D");
    list.display(); 
    list.deletefirst();
   // list.deletelast();
    list.display(); 
    cout<<"size of linkedlist="<<list.capacity()<<endl;
    return 0;
}