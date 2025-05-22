//cscan

#include<iostream>
using namespace std;

class LL{
    public:
    int size;
    int disksize;
    class Node{
        public:
        int data;
        Node *next;
        public:
        Node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
    };
    Node *head;
    LL(int disksize)
    {
        this->size=0;
        this->head=NULL;
        this->disksize=disksize;
    }
    void addlast(int val)
    {
        Node *newnode=new Node(val);
       
        if(head==NULL)
        {
            head=newnode;
            size++;
            return;
        }
        Node *current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
        size++;
    }
    void selectionsortasc()
    {
        int i,j;
        Node*start=head;
        while(start!=NULL)
        {
            Node *min=start;
            Node *current=start->next;
            while(current!=NULL)
            {
                if(min->data>current->data)
                {
                    min=current;
                }
                current=current->next;
            }
            int temp=start->data;
                start->data=min->data;
                min->data=temp;
                start=start->next;
        }
    }
    
    void scan(int start)
    {
        selectionsortasc();
        Node *current=head;
        LL left(disksize),right(disksize);
        while(current!=NULL)
        {
            if(start<=current->data)
            {
                right.addlast(current->data);
            }
            if(start>current->data)
            {
                left.addlast(current->data);
            }
            current=current->next;
        }
        right.selectionsortasc();
        left.selectionsortasc();
        cout << "C-SCAN Order starting from " << start << ": ";

        Node *r=right.head;
        while(r!=NULL)
        {
            cout<<r->data<<" ";
            r=r->next;
        }
        cout<<"->"<< disksize-1<<"-> 0 ->"<<" ";
        Node *l=left.head;
        while(l!=NULL)
        {
            cout<<l->data<<" ";
            l=l->next;
        }



    }
    void printlist()
    {
        Node *currnode=head;
        while(currnode!=nullptr)
        {
            cout<<currnode->data<<"->";
            currnode=currnode->next;
        }
        cout << "NULL" << endl;
    }
    int getSize() {
        return size;
    }
};
int main()
{
    int diskSize = 200;
    LL requests(diskSize);

    // Sample disk I/O requests
    int arr[] = {98, 183, 37, 32, 14, 28, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        requests.addlast(arr[i]);
    }

    int headPosition = 50;
    requests.scan(headPosition);

    return 0;
}