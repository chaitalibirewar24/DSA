//binary search tree

#include<iostream>
using namespace std;

class bst{
    public:
    int size;
    class Node{
        public:
        int data;
        Node *left,*right;
        public:
        Node(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
    };
    Node *root;
    public:
    bst()
    {
        root=NULL;
    }
    Node* insert(Node *current ,int val)//alternate way=return type =Node pointer (Node *)
    {
        if(current == NULL)
        {current=new Node(val);
            return new Node(val);
       }
        if(val<current->data )
        {
            current->left=insert(current->left,val);
            //insert(current->left,val);
        }
        else{
            current->right=insert(current->right,val);
            //insert(current->right,val);
        }
       // return current;
    }
    void insert(int val) {
        root = insert(root, val);
        //insert(root, val);
    }
    //search

    bool search(Node *current ,int val)
    {
        if(current==NULL)
        {
            return false;
        }
        if(current->data==val)
        {
            return true;
        }
        else if(current->data<val)
        {
           return search(current->right,val);
        }
        else
        {
            return search(current->left,val);
        }
    }

    bool search(int val)
    {
        return search(root,val);
    }

    //traverse:
    void inorder(Node *current)
    {
        if(current==NULL)
        {
            return;
        }
        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }
    void inorder()
    {
        cout<<"inorder:";
        inorder(root);
        cout<<endl;
    }

    void preorder(Node *current)
    {
        if(current==NULL)
        {
            return;
        }
        cout << current->data << " ";
        preorder(current->left);
        preorder(current->right);
    }
    void preorder()
    {
        cout<<"preorder:";
        preorder(root);
        cout<<endl;
    }

    void postorder(Node *current)
    {
        if(current==NULL)
        {
            return;
        }
        postorder(current->left);
        postorder(current->right);
        cout << current->data << " ";
    }
    void postorder()
    {
        cout<<"postorder:";
        postorder(root);
        cout<<endl;
    }
    // delete dunction

    Node* findMin(Node* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    Node* deletenode(Node *current,int val)
    {
        
        if(!search(val))
        {
            cout<<"value does not exit"<<endl;
        }
        if(current==NULL)
        {
            cout<<"empty"<<endl;
        }
        if(val<current->data)
        {
            current->left=deletenode(current->left,val);
        }
        else if(val>current->data)
        {
            current->right=deletenode(current->right,val);
        }else{
            if(current->left==NULL)
            {
                Node* temp = current->right;
                delete current;
                size--;
                return temp;
            } else if (current->right == NULL) {
                Node* temp = current->left;
                delete current;
                size--;
                return temp;
            }
            Node *temp=findMin(current->right);
            current->data=temp->data;
            current->right=deletenode(current->right,temp->data);
            return current;
        }
    }
    void deleteNode(int val) {
        root = deletenode(root, val);
    }
    
};

int main()
{
    bst tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    //cout<<tree.search(70);
    cout << "Search 70: " << (tree.search(70) ? "Found" : "Not Found") << endl;
    // Traversals
    tree.inorder();    // 20 30 40 50 60 70 80
    tree.preorder();   // 50 30 20 40 70 60 80
    tree.postorder();  // 20 40 30 60 80 70 50
    tree.deleteNode(20); // leaf
    tree.deleteNode(30); // node with one child
    tree.deleteNode(50); // node with two children
    tree.inorder();    // 20 30 40 50 60 70 80
    tree.preorder();   // 50 30 20 40 70 60 80
    tree.postorder();  // 20 40 30 60 80 70 50

    return 0;
}