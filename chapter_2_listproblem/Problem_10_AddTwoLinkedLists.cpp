#include <iostream>
#include <stack>
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

Node* addList1(Node* head1, Node* head2)
{
    stack<int> s1;
    stack<int> s2;
    while(head1 != NULL)
    {
        s1.push(head1->value);
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        s2.push(head2->value);
        head2 = head2->next;
    }
    int ca = 0;
    int n1 = 0;
    int n2 = 0;
    int n = 0;
    Node* node = NULL;
    Node* pre = NULL;
    while(!s1.empty() || !s2.empty())
    {
        if(s1.empty())
        {
            n1 = 0;
        }
        else
        {
            n1 = s1.top();
            s1.pop();
        }
        if(s2.empty())
        {
            n2 = 0;
        }
        else
        {
            n2 = s2.top();
            s2.pop();
        }
        n = n1 + n2 + ca;
        pre = node;
        node = new Node(n % 10);
        node->next = pre;
        ca = n / 10;
    }

    if(ca == 1)
    {
        pre = node;
        node = new Node(1);
        node->next = pre;
    }
    return node;
}

Node* reverseList(Node* head)
{
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

// 不用额外的空间
Node* addList2(Node* head1, Node* head2)
{
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    int ca = 0;
    int n1 = 0;
    int n2 = 0;
    int n = 0;
    Node* c1 = head1;
    Node* c2 = head2;
    Node* node = NULL;
    Node* pre = NULL;
    while(c1 != NULL || c2 != NULL)
    {
        n1 = c1 != NULL ? c1->value : 0;
        n2 = c2 != NULL ? c2->value : 0;
        n = n1 + n2 + ca;
        pre = node;
        node = new Node(n % 10);
        node->next = pre;
        ca = n / 10;
        c1 = c1 != NULL ? c1->next : NULL;
        c2 = c2 != NULL ? c2->next : NULL;
    }
    if(ca == 1)
    {
        pre = node;
        node = new Node(1);
        node->next = pre;
    }

    reverseList(head1);
    reverseList(head2);
    return node;
}

int main()
{
    Node* head1 = new Node(9);
    head1->next = new Node(9);
    head1->next->next = new Node(9);
    Node* head2 = new Node(1);

    printLinkedList(head1);
    printLinkedList(head2);
    printLinkedList(addList1(head1, head2));
    printLinkedList(addList2(head1, head2));
    return 0;
}
