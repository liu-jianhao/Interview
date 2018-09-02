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


bool isPalindrome1(Node* head)
{
    stack<Node*> stack;
    Node* cur = head;
    while(cur != NULL)
    {
        stack.push(cur);
        cur = cur->next;
    }
    while(head != NULL)
    {
        if(head->value != stack.top()->value)
        {
            return false;
        }
        head = head->next;
        stack.pop();
    }
    return true;
}


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

int main()
{
    Node* head = NULL;
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(2);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(1);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    printLinkedList(head);
    if(isPalindrome1(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    printLinkedList(head);
    cout << "========================" << endl;

    return 0;
}
