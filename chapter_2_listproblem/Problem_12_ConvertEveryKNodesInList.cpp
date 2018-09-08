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


Node* resign1(stack<Node*> stack, Node* left, Node* right)
{
    Node* cur = stack.top();
    stack.pop();
    if(left != NULL)
    {
        left->next = cur;
    }
    Node* next = NULL;
    while(!stack.empty())
    {
        next = stack.top();
        stack.pop();
        cur->next = next;
        cur = next;
    }
    cur->next = right;
    return cur;
}

// 利用栈
Node* reverseKNodes1(Node* head, int K)
{
    if(K < 2)
    {
        return head;
    }

    stack<Node*> stack;
    Node* newHead = head;
    Node* cur = head;
    Node* pre = NULL;
    Node* next = NULL;
    while(cur != NULL)
    {
        next = cur->next;
        stack.push(cur);
        if(stack.size() == K)
        {
            pre = resign1(stack, pre, next);
            newHead = newHead == head ? cur : newHead;
        }
        cur = next;
    }
    return newHead;
}


void resign2(Node* left, Node* start, Node* end, Node* right)
{
    Node* pre = start;
    Node* cur = start->next;
    Node* next = NULL;
    while(cur != right)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    if(left != NULL)
    {
        left->next = end;
    }
    start->next = right;
}

// 不用栈
Node* reverseKNodes2(Node* head, int K)
{
    if(K < 2)
    {
        return head;
    }

    Node* cur = head;
    Node* start = NULL;
    Node* pre = NULL;
    Node* next = NULL;
    int count = 1;
    while(cur != NULL)
    {
        next = cur->next;
        if(count == K)
        {
            start = pre == NULL ? head : pre->next;
            head = pre == NULL ? cur : head;
            resign2(pre, start, cur, next);
            pre = start;
            count = 0;
        }
        count++;
        cur = next;
    }
    return head;
}

int main()
{
    Node* head = NULL;
    int K = 3;
    printLinkedList(head);
    head = reverseKNodes1(head, K);
    printLinkedList(head);
    head = reverseKNodes2(head, K);
    printLinkedList(head);
    cout << "=======================";

    head = new Node(1);
    K = 3;
    printLinkedList(head);
    head = reverseKNodes1(head, K);
    printLinkedList(head);
    head = reverseKNodes2(head, K);
    printLinkedList(head);
    cout << "=======================";

    head = new Node(1);
    head->next = new Node(2);
    K = 2;
    printLinkedList(head);
    head = reverseKNodes1(head, K);
    printLinkedList(head);
    head = reverseKNodes2(head, K);
    printLinkedList(head);
    cout << "=======================";

    head = new Node(1);
    head->next = new Node(2);
    K = 3;
    printLinkedList(head);
    head = reverseKNodes1(head, K);
    printLinkedList(head);
    head = reverseKNodes2(head, K);
    printLinkedList(head);
    cout << "=======================";

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    K = 2;
    printLinkedList(head);
    head = reverseKNodes1(head, K);
    printLinkedList(head);
    head = reverseKNodes2(head, K);
    printLinkedList(head);
    cout << "=======================";

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    K = 3;
    printLinkedList(head);
    head = reverseKNodes1(head, K);
    printLinkedList(head);
    head = reverseKNodes2(head, K);
    printLinkedList(head);
    cout << "=======================";

    return 0;
}
