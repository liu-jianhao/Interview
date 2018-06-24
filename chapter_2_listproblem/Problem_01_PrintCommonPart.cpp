#include <iostream>

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

void printCommonPart(Node *head1, Node *head2)
{
    cout << "Common Part: " << endl;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->value < head2->value)
        {
            head1 = head2->next;
        }
        else if(head1->value > head2->value)
        {
            head2 = head2->next;
        }
        else
        {
            cout << head1->value << " ";
            head1 = head1->next;
            head2 = head2->next;
        }
        cout << endl;
    }
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
    Node *node1 = new Node(2);
    node1->next = new Node(3);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(6);


    Node *node2 = new Node(1);
    node2->next = new Node(2);
    node2->next->next = new Node(5);
    node2->next->next->next = new Node(7);
    node2->next->next->next->next = new Node(8);

    printLinkedList(node1);
    printLinkedList(node2);
    printCommonPart(node1, node2);
    return 0;
}
