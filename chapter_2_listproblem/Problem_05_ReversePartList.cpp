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

Node* reversePart(Node* head, int from, int to)
{
    int len = 0;
    Node* node1 = head;
    // 反转部分的前一个节点
    Node* fPre = NULL;
    // 反转部分的后一个节点
    Node* tPos = NULL;

    while(node1 != NULL)
    {
        len++;
        // 先找到第from-1个节点和第to+1个节点
        fPre = len == from - 1 ? node1 : fPre;
        tPos = len == to + 1 ? node1 : tPos;
        node1 = node1->next;
    }

    if(from > to || from < 1 || to > len)
    {
        return head;
    }
    node1 = fPre == NULL ? head : fPre->next;
    Node* node2 = node1->next;
    node1->next = tPos;
    Node* next = NULL;

    // 开始反转
    while(node2 != tPos)
    {
        next = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = next;
    }

    // 如果fPre为NULL，说明反转部分包含头结点，则返回新的头结点
    if(fPre != NULL)
    {
        fPre->next = node1;
        return head;
    }

    return node1;
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
    head = reversePart(head, 1, 1);
    printLinkedList(head);

    head = new Node(1);
    printLinkedList(head);
    head = reversePart(head, 1, 1);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    printLinkedList(head);
    head = reversePart(head, 1, 2);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    printLinkedList(head);
    head = reversePart(head, 1, 3);
    printLinkedList(head);

    return 0;
}
