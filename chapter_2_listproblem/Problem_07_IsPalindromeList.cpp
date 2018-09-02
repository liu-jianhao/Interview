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

// 只将右半部分压入栈
bool isPalindrome2(Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;
    Node* right = head->next;
    Node* cur = head;
    while(cur->next != NULL && cur->next->next != NULL)
    {
        right = right->next;
        cur = cur->next->next;
    }
    stack<Node*> stack;
    while(right != NULL)
    {
        stack.push(right);
        right = right->next;
    }
    while(!stack.empty())
    {
        if(head->value != stack.top()->value)
        {
            return false;
        }
        stack.pop();
        head = head->next;
    }
    return true;
}

// 不用额外的空间
bool isPalindrome3(Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;
    Node* n1 = head;
    Node* n2 = head;
    // 查找到中间结点
    while(n2->next != NULL && n2->next->next != NULL)
    {
        n1 = n1->next; // n1指向中部
        n2 = n2->next->next; // n2指向尾部
    }
    n2 = n1->next; // 右边的第一个节点
    n1->next = NULL;
    Node* n3 = NULL;
    // 右半区反转
    while(n2 != NULL)
    {
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }

    n3 = n1;
    n2 = head;
    bool res = true;
    // 检查回文结构
    while(n1 != NULL && n2 != NULL)
    {
        if(n1->value != n2->value)
        {
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }

    n1 = n3->next;
    n3->next = NULL;
    // 恢复链表
    while(n1 != NULL)
    {
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
    return res;
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
    if(isPalindrome1(head) && isPalindrome2(head) && isPalindrome3(head))
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
