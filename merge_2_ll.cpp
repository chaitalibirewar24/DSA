#include<iostream>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void addLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Merge two sorted linked lists
     Node* mergeSortedLists(Node* list1, Node* list2) {
        // Create a dummy node to help with the merging
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        // Compare nodes from both lists and merge
        while (list1 && list2) {
            if (list1->data < list2->data) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // If any list has remaining nodes, add them to the merged list
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the merged list starting from the next node of the dummy
        Node* mergedHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return mergedHead;
    }
};

int main() {
    LinkedList list1;
    list1.addLast(1);
    list1.addLast(3);
    list1.addLast(5);

    LinkedList list2;
    list2.addLast(2);
    list2.addLast(4);
    list2.addLast(6);

    cout << "List 1: ";
    list1.printList();
    cout << "List 2: ";
    list2.printList();

    

    cout << "Merged List: ";
    LinkedList mergedList;
    mergedList.head=mergedList.mergeSortedLists(list1.head, list2.head);
    mergedList.printList();

    return 0;
}
