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


void printCircularList(Node* head)
{
    cout << "Circular List: " << head->value << " ";
    Node* cur = head->next;
    while(cur != head)
    {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << "-> " << head->value << endl;
}

Node* insertNum(Node* head, int num)
{
    Node* node = new Node(num);
    if(head == NULL)
    {
        node->next = node;
        return node;
    }
    Node* pre = head;
    Node* cur = head->next;
    while(cur != head)
    {
        if(pre->value <= num && cur->value >= num)
        {
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = node;
    node->next = cur;
    return head->value < num ? head : node;
}

int main()
{
    Node* head = NULL;
    head = insertNum(head, 2);
    printCircularList(head);
    head = insertNum(head, 1);
    printCircularList(head);
    head = insertNum(head, 4);
    printCircularList(head);
    head = insertNum(head, 3);
    printCircularList(head);
    head = insertNum(head, 5);
    printCircularList(head);
    head = insertNum(head, 0);
    printCircularList(head);

    return 0;
}
