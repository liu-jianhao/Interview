#include <iostream>
#include <cmath>

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

Node* removeMidNode(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    if(head->next->next == NULL)
    {
        return head->next;
    }

    Node *pre = head;
    Node *cur = head->next->next;
    while(cur->next != NULL && cur->next->next != NULL)
    {
        pre = pre->next;
        cur = cur->next->next;
    }

    pre->next = pre->next->next;
    return head;
}

Node* removeByRatio(Node* head, int a, int b)
{
    if(a < 1 || a > b)
    {
        return head;
    }
    int n = 0;
    Node* cur = head;
    while(cur != NULL)
    {
        n++;
        cur = cur->next;
    }
    n = static_cast<int>(ceil(static_cast<double>(a * n) / static_cast<double>(b)));
    if(n == 1)
    {
        head = head->next;
    }
    if(n > 1)
    {
        cur = head;
        while(--n != 1)
        {
            cur = cur->next;
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

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    printLinkedList(head);
    head = removeMidNode(head);
    printLinkedList(head);
    head = removeByRatio(head, 2, 5);
    printLinkedList(head);
    head = removeByRatio(head, 1, 3);
    printLinkedList(head);

    return 0;
}
