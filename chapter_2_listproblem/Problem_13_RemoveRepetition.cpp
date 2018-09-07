#include <iostream>
#include <unordered_set>
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

// 使用哈希表
void removeReq1(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    unordered_set<int> set;
    Node* pre = head;
    Node* cur = head->next;
    set.insert(head->value);
    while(cur != NULL)
    {
        if(set.find(cur->value) != set.end())
        {
            pre->next = cur->next;
        }
        else
        {
            set.insert(cur->value);
            pre = cur;
        }
        cur = cur->next;
    }
}


// 类似选择排序
void removeReq2(Node* head)
{
    Node* cur = head;
    Node* pre = NULL;
    Node* next = NULL;
    while(cur != NULL)
    {
        pre = cur;
        next = cur->next;
        while(next != NULL)
        {
            if(cur->value == next->value)
            {
                pre->next = next->next;
            }
            else
            {
                pre = next;
            }
            next = next->next;
        }
        cur = cur->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->next = new Node(1);
    printLinkedList(head);
    removeReq1(head);
    printLinkedList(head);

    cout << endl;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->next = new Node(1);
    printLinkedList(head);
    removeReq2(head);
    printLinkedList(head);


    return 0;
}
