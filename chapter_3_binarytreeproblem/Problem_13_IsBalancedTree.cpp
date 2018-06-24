#include <iostream>
#include <cmath>

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

int getHeight(Node* head, int level, bool &res)
{
    if(head == NULL)
    {
        return level;
    }

    int lH = getHeight(head->left, level+1, res);
    if(!res)
    {
        return level;
    }

    int rH = getHeight(head->right, level+1, res);
    if(!res)
    {
        return level;
    }

    if(abs(lH - rH) > 1)
        res = false;

    return max(lH, rH);
}

bool isBalance(Node* head)
{
    bool res = true;
    getHeight(head, 1, res);
    return res;
}



int main()
{
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);

    cout << isBalance(head) << endl;
    return 0;
}
