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

Node* removeLastKthNode(Node *head, int lastKth)
{
    if(head == NULL || lastKth < 1)
    {
        return head;
    }
    Node* cur = head;
    while(cur != NULL)
    {
        lastKth--;
        cur = cur->next;
    }
    if(lastKth == 0)
    {
        head = head->next;
    }
    if(lastKth < 0)
    {
        cur = head;
        while(++lastKth != 0)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;
}

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

DoubleNode* removeLastKthNode(DoubleNode *head, int lastKth)
{
    if(head == NULL || lastKth < 1)
    {
        return head;
    }
    DoubleNode* cur = head;
    while(cur != NULL)
    {
        lastKth--;
        cur = cur->next;
    }
    if(lastKth == 0)
    {
        head = head->next;
        head->last = NULL;
    }
    if(lastKth < 0)
    {
        cur = head;
        while(++lastKth != 0)
        {
            cur = cur->next;
        }
        DoubleNode *newNext = cur->next->next;
        cur->next = newNext;
        if(newNext != NULL)
        {
            newNext->last = cur;
        }
        cur->next = cur->next->next;
    }
    return head;
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
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    printLinkedList(head1);
    head1 = removeLastKthNode(head1, 3);
    printLinkedList(head1);

    DoubleNode *head2 = new DoubleNode(1);
    head2->next = new DoubleNode(2);
    head2->next->last = head2;
    head2->next->next = new DoubleNode(3);
    head2->next->next->last = head2;
    head2->next->next->next = new DoubleNode(4);
    head2->next->next->next->last = head2;
    head2->next->next->next->next = new DoubleNode(5);
    head2->next->next->next->next->last = head2;
    head2->next->next->next->next->next = new DoubleNode(6);
    head2->next->next->next->next->next->last = head2->next->next->next->next;
    printDoubleLinkedList(head2);
    head2 = removeLastKthNode(head2, 3);
    printDoubleLinkedList(head2);

    return 0;
}
