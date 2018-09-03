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

void arrPatition(Node* nodeArr[], int pivot, int size)
{
    int small = -1;
    int big = size;
    int index = 0;
    while(index != big)
    {
        if(nodeArr[index]->value < pivot)
        {
            swap(nodeArr[++small], nodeArr[index++]);
        }
        else if(nodeArr[index]->value == pivot)
        {
            index++;
        }
        else
        {
            swap(nodeArr[--big], nodeArr[index]);
        }
    }
}


Node* listPartition1(Node* head, int pivot)
{
    if(head == NULL)
    {
        return head;
    }

    Node* cur = head;
    int i = 0;
    // 得出长度
    while(cur != NULL)
    {
        i++;
        cur = cur->next;
    }
    const int size = i;
    Node* nodeArr[size];
    i = 0;
    cur = head;
    for(i = 0; i != size; i++)
    {
        nodeArr[i] = cur;
        cur = cur->next;
    }
    arrPatition(nodeArr, pivot, size);
    // 重新组织链表
    for(i = 1; i != size; i++)
    {
        nodeArr[i-1]->next = nodeArr[i];
    }
    nodeArr[i-1]->next = NULL;
    return nodeArr[0];
}

// 不适用额外的空间
// 将链表分为三个链表，然后再串起来
Node* listPartition2(Node* head, int pivot)
{
    Node* sH = NULL; // small head
    Node* sT = NULL; // small tail
    Node* eH = NULL; // equal head
    Node* eT = NULL; // equal tail
    Node* bH = NULL; // big head
    Node* bT = NULL; // big tail
    Node* next = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = NULL;
        if(head->value < pivot)
        {
            if(sH == NULL)
            {
                sH = head;
                sT = head;
            }
            else
            {
                sT->next = head;
                sT = head;
            }
        }
        else if(head->value == pivot)
        {
            if(eH == NULL)
            {
                eH = head;
                eT = head;
            }
            else
            {
                eT->next = head;
                eT = head;
            }
        }
        else
        {
            if(bH == NULL)
            {
                bH = head;
                bT = head;
            }
            else
            {
                bT->next = head;
                bT = head;
            }
        }
        head = next;
    }

    if(sT != NULL)
    {
        sT->next = eH;
        eT = eT == NULL ? sT : eT;
    }
    if(eT != NULL)
    {
        eT->next = bH;
    }
    return sH != NULL ? sH : eH != NULL ? eH : bH;
}

int main()
{
    Node* head1 = new Node(7);
    head1->next = new Node(9);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(8);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(2);
    head1->next->next->next->next->next->next = new Node(5);
    printLinkedList(head1);
    //head1 = listPartition1(head1, 5);
    head1 = listPartition2(head1, 5);
    printLinkedList(head1);
}
