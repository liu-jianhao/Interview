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


void mergeLR(Node* left, Node* right)
{
    Node* next = NULL;
    while(left->next != NULL)
    {
        next = right->next;
        right->next = left->next;
        left->next = right;
        left = right->next;
        right = next;
    }
    left->next = right;
}

void relocate(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    Node* mid = head;
    Node* right = head->next;
    while(right->next != NULL && right->next->next != NULL)
    {
        mid = mid->next;
        right = right->next->next;
    }
    right = mid->next;
    mid->next = NULL;
    mergeLR(head, right);
}

int main()
{
    Node* head = NULL;
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    relocate(head);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    relocate(head);
    printLinkedList(head);


    return 0;
}
