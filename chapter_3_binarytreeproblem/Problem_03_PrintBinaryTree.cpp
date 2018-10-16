#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int data)
        {
            value = data;
        }

        ~Node(){}
};

string getSpace(int num)
{
    string space = " ";
    string buf;
    for(int i = 0; i < num; ++i)
    {
        buf += space;
    }
    return buf;
}

void printInOrder(Node *head, int height, string to, int len)
{
    if(head == nullptr)
    {
        return;
    }

    printInOrder(head->right, height+1, "v", len);
    char v[10];
    sprintf(v, "%d", head->value);
    string val = to + v + to;
    int lenM = val.size();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val << endl;
    printInOrder(head->left, height+1, "^", len);
}

void printTree(Node *head)
{
    cout << "Binary Tree:";
    printInOrder(head, 0, "H", 17);
    cout << endl;
}


int main()
{
    Node *head = new Node(1);
    head->left = new Node(-222222222);
    head->right = new Node(3);
    head->left->left = new Node(INT_MIN);
    head->right->left = new Node(55555555);
    head->right->right = new Node(66);
    head->left->left->right = new Node(777);
    printTree(head);

    head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(5);
    head->right->right = new Node(6);
    head->left->left->right = new Node(7);
    printTree(head);

    head = new Node(1);
    head->left = new Node(1);
    head->right = new Node(1);
    head->left->left = new Node(1);
    head->right->left = new Node(1);
    head->right->right = new Node(1);
    head->left->left->right = new Node(1);
    printTree(head);

    return 0;
}
