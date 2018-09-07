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

Node* removeValue(Node* head, int num)
{
    // 找到第一个值不为num的节点
    while(head != NULL)
    {
        if(head->value != num)
        {
            break;
        }
        head = head->next;
    }

    Node* cur = head;
    Node* pre = head;
    while(cur != NULL)
    {
        if(cur->value == num)
        {
            pre->next = cur->next;
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next = new Node(1);
    printLinkedList(head);
    head = removeValue(head, 1);
    printLinkedList(head);

    return 0;
}
