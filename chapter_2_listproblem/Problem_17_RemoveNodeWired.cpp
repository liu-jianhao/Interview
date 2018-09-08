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

void removeNodeWired(Node* node)
{
    if(node == NULL)
    {
        return;
    }
    Node* next = node->next;
    if(next == NULL)
    {
        throw "can not remove last node.";
    }
    node->value = next->value;
    node->next = next->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node* node = head;
    printLinkedList(head);
    removeNodeWired(node);
    printLinkedList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    node = head->next;
    printLinkedList(head);
    removeNodeWired(node);
    printLinkedList(head);


    return 0;
}
