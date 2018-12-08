#include <iostream>

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

int mostLeftLevel(Node* node, int level)
{
    while(node != nullptr)
    {
        ++level;
        node = node->left;
    }
    return level-1;
}

int bs(Node* node, int l, int h)
{
    if(l == h)
    {
        return 1;
    }

    if(mostLeftLevel(node->right, l+1) == h)
    {
        return (1 << (h-1)) + bs(node->right, l+1, h);
    }
    else
    {
        return (1 << (h-l-1)) + bs(node->left, l+1, h);
    }
}

int nodeNum(Node* head)
{
    if(head == nullptr)
    {
        return 0;
    }

    return bs(head, 1, mostLeftLevel(head, 1));
}


int main()
{
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(5);

    cout << nodeNum(head) << endl;
}
