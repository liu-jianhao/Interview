#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

    public:
        Node(int data)
        {
            value = data;
        }
        ~Node(){}
};


void printLinkedList(Node* head)
{
    cout << "Linked List: ";
    while(head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getSmallestPreNode(Node* head)
{
    Node* smallPre = NULL;
    Node* small = head;
    Node* pre = head;
    Node* cur = head->next;
    while(cur != NULL)
    {
        if(cur->value < small->value)
        {
            smallPre = pre;
            small = cur;
        }
        pre = cur;
        cur = cur->next;
    }
    return smallPre;
}

Node* selectionSort(Node* head)
{
    Node* tail = NULL;
    Node* cur = head;
    Node* smallPre = NULL;
    Node* small = NULL;
    while(cur != NULL)
    {
        small = cur;
        smallPre = getSmallestPreNode(cur);
        if(smallPre != NULL)
        {
            small = smallPre->next;
            smallPre->next = small->next;
        }
        cur = cur == small ? cur->next : cur;
        if(tail == NULL)
        {
            head = small;
        }
        else
        {
            tail->next = small;
        }
        tail = small;
    }
    return head;
}

int main()
{
    Node* head = NULL;
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(1);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(2);
    head->next = new Node(1);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head = selectionSort(head);
    printLinkedList(head);

    head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);
    head = selectionSort(head);
    printLinkedList(head);


    return 0;
}
