#include <iostream>
#include <queue>
#include <string>

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

bool isBST(Node* head)
{
    if(head == nullptr)
    {
        return true;
    }

    bool res = true;
    Node* pre = nullptr;
    Node* cur1 = head;
    Node* cur2 = nullptr;
    while(cur1 != nullptr)
    {
        cur2 = cur1->left;
        if(cur2 != nullptr)
        {
            while(cur2->right != nullptr && cur2->right != cur1)
            {
                cur2 = cur2->right;
            }
            if(cur2->right == nullptr)
            {
                cur2->right = cur1;
                cur1 = cur1->left;
                continue;
            }
            else
            {
                cur2->right = nullptr;
            }
        }

        if(pre != nullptr && pre->value > cur1->value)
        {
            res = false;
        }

        pre = cur1;
        cur1 = cur1->right;
    }

    return res;
}

bool isCBT(Node* head)
{
    if(head == nullptr)
    {
        return true;
    }

    queue<Node*> queue;
    bool leaf = false;
    Node* l = nullptr;
    Node* r = nullptr;
    queue.push(head);
    while(!queue.empty())
    {
        head = queue.front();
        queue.pop();
        l = head->left;
        r = head->right;
        if((leaf && (l != nullptr || r != nullptr)) || (l == nullptr && r != nullptr))
        {
            return false;
        }
        if(l != nullptr)
        {
            queue.push(l);
        }
        if(r != nullptr)
        {
            queue.push(r);
        }
        else
        {
            leaf = true;
        }
    }

    return true;
}

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
    Node* head = new Node(4);
    head->left = new Node(2);
    head->right = new Node(6);
    head->left->left = new Node(1);
    head->left->right = new Node(3);
    head->right->left = new Node(5);

    printTree(head);

    cout << isBST(head) << endl;
    cout << isCBT(head) << endl;

    return 0;
}
