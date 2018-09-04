#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* rand;

    public:
        Node(int data)
        {
            value = data;
        }
        ~Node(){}
};

Node* copyListWithRand1(Node* head)
{
    unordered_map<Node*, Node*> map;
    Node* cur = head;
    while(cur != NULL)
    {
        map.insert({cur, new Node(cur->value)});
        cur = cur->next;
    }
    cur = head;
    while(cur != NULL)
    {
        map[cur]->next = map[cur->next];
        cur = cur->next;
    }
    return map[head];
}

Node* copyListWithRand2(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* cur = head;
    Node* next = NULL;
    // 复制每一个节点并放在后一个节点处
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = new Node(cur->value);
        cur->next->next = next;
        cur = next;
    }

    cur = head;
    Node* curCopy = NULL;
    while(cur != NULL)
    {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != NULL ? cur->rand->next : NULL;
        cur = next;
    }
    Node* res = head->next;
    cur = head;
    while(cur != NULL)
    {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next != NULL ? next->next : NULL;
        cur = next;
    }
    return res;
}

void printRandLinkedList(Node* head)
{
    Node* cur = head;
    cout << "order: ";
    while(cur != NULL)
    {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
    cur = head;
    cout << "rand: ";
    while(cur != NULL)
    {
        if(cur->rand == NULL)
        {
            cout << "- ";
        }
        else
        {
            cout << cur->rand->value << " ";
        }
        cur = cur->next;
    }
    cout << endl;
}


int main()
{
    Node* head = NULL;
    Node* res1 = NULL;
    Node* res2 = NULL;
    printRandLinkedList(head);
    res1 = copyListWithRand1(head);
    printRandLinkedList(res1);
    res2 = copyListWithRand1(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);
    cout << "==========================";

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head->rand = head->next->next->next->next->next; // 1 -> 6
    head->next->rand = head->next->next->next->next->next; // 2 -> 6
    head->next->next->rand = head->next->next->next->next; // 3 -> 5
    head->next->next->next->rand = head->next->next; // 4 -> 3
    head->next->next->next->next->rand = NULL; // 5 -> NULL
    head->next->next->next->next->next->rand = head->next->next->next; // 6 -> 4

    printRandLinkedList(head);
    res1 = copyListWithRand1(head);
    printRandLinkedList(res1);
    res2 = copyListWithRand1(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);

    cout << "==========================";

    return 0;
}
