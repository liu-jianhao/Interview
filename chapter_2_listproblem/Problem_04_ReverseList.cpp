#include <iostream>

using namespace std;

class Node{
public:
    Node(int data)
    {
        value = data;
    }

    ~Node(){}

    Node *next;
    int value;
};

class DoubleNode{
public:
    DoubleNode(int data)
    {
        value = data;
    }

    ~DoubleNode(){}

    DoubleNode *next, *last;
    int value;
};


Node* reverseList(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* pre = NULL;
    Node* next = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

DoubleNode* reverseList(DoubleNode* head)
{
    DoubleNode* pre = NULL;
    DoubleNode* next = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}


void printLinkedList(Node *node)
{
    cout << "Linked List: ";
    while(node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void printDoubleLinkedList(DoubleNode* head)
{
    cout << "Double Linked List: ";
    DoubleNode* end = NULL;
    while(head != NULL)
    {
        cout << head->value << " ";
        end = head;
        head = head->next;
    }
    cout << "| ";
    while(end != NULL)
    {
        cout << end->value << " ";
        end = end->last;
    }
    cout << endl;
}


int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    printLinkedList(head1);
    head1 = reverseList(head1);
    printLinkedList(head1);


    DoubleNode* head2 = new DoubleNode(1);
    head2->next = new DoubleNode(2);
    head2->next->last = head2;
    head2->next->next = new DoubleNode(3);
    head2->next->next->last = head2->next;
    head2->next->next->next = new DoubleNode(4);
    head2->next->next->next->last = head2->next->next;
    printDoubleLinkedList(head2);
    head2 = reverseList(head2);
    printDoubleLinkedList(head2);


    return 0;
}
