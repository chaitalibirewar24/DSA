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
        Node *start=head;
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
    void selectionsortdes()
    {
        int i,j;
        Node*start=head;
        while(start!=NULL)
        {
            Node *max=start;
            Node *current=start->next;
            while(current!=NULL)
            {
                if(max->data<current->data)
                {
                    max=current;
                }
                current=current->next;
            }
            int temp=start->data;
                start->data=max->data;
                max->data=temp;
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
        left.selectionsortdes();
        cout << "SCAN Order starting from " << start << ": ";

        int totalmoments=0;
        int currenthead=start;

        Node *r = right.head;
        while (r != NULL)
        {
            cout << r->data << " ";
            if (currenthead > r->data)
            {
                totalmoments += (currenthead - r->data);
            }
            else
            {
                totalmoments += r->data - currenthead;
            }
            currenthead = r->data;
            r = r->next;
        }
         // Move to the maximum disk size (diskSize-1)
         if (currenthead < disksize - 1)
         {
             totalmoments += (disksize - 1) - currenthead;
             currenthead = disksize - 1;
         }
         else if (currenthead > disksize - 1)
         {
             totalmoments += currenthead - (disksize - 1);
             currenthead = disksize - 1;
         }
         cout << disksize - 1 << "-> ";
        
        // Left movement
        Node *l = left.head;
        while (l != NULL)
        {
            cout << l->data << " ";
            if (currenthead > l->data)
            {
                totalmoments += currenthead - l->data;
            }
            else
            {
                totalmoments += l->data - currenthead;
            }
            currenthead = l->data;
            l = l->next;
        }
        cout << endl;
        cout << "Total Head Movement: " << totalmoments << " cylinders" << endl;



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
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        requests.addlast(arr[i]);
    }

    int headPosition = 50;
    requests.scan(headPosition);

    return 0;
}