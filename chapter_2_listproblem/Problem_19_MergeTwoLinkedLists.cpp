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


Node* merge(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return head1 != NULL ? head1 : head2;
    }

    Node* head = head1->value < head2->value ? head1 : head2;
    Node* cur1 = head == head1 ? head1 : head2;
    Node* cur2 = head == head1 ? head2 : head1;
    Node* pre = NULL;
    Node* next = NULL;
    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1->value <= cur2->value)
        {
            pre = cur1;
            cur1 = cur1->next;
        }
        else
        {
            next = cur2->next;
            pre->next = cur2;
            cur2->next = cur1;
            pre = cur2;
            cur2 = next;
        }
    }
    pre->next = cur1 == NULL ? cur2 : cur1;
    return head;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head = merge(head1, head2);
    printLinkedList(head);

    head1 = new Node(1);
    head2 = NULL;
    head = merge(head1, head2);
    printLinkedList(head);

    head1 = NULL;
    head2 = new Node(1);
    head = merge(head1, head2);
    printLinkedList(head);

    head1 = new Node(1);
    head2 = new Node(2);
    head = merge(head1, head2);
    printLinkedList(head);

    head1 = new Node(2);
    head2 = new Node(1);
    head = merge(head1, head2);
    printLinkedList(head);


    head1 = new Node(1);
    head1->next = new Node(4);
    head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(5);
    head = merge(head1, head2);
    printLinkedList(head);

    head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(9);
    head2 = new Node(0);
    head2->next = new Node(6);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(7);
    head = merge(head1, head2);
    printLinkedList(head);

    return 0;
}
