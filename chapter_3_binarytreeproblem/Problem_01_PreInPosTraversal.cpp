#include <iostream>
#include <stack>

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

void preOrderRecur(Node* head)
{
    if(head == NULL)
        return;

    cout << head->value << " ";
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

void inOrderRecur(Node* head)
{
    if(head == NULL)
        return;

    inOrderRecur(head->left);
    cout << head->value << " ";
    inOrderRecur(head->right);
}

void posOrderRecur(Node* head)
{
    if(head == NULL)
        return;

    posOrderRecur(head->left);
    posOrderRecur(head->right);
    cout << head->value << " ";
}


void preOrderUnRecur(Node* head)
{
    cout << "pre-order: ";
    if(head != NULL)
    {
        stack<Node*> stack;
        stack.push(head);
        while(!stack.empty())
        {
            head = stack.top();
            stack.pop();
            cout << head->value << " ";
            if(head->right != NULL)
            {
                stack.push(head->right);
            }
            if(head->left != NULL)
            {
                stack.push(head->left);
            }
        }
    }
    cout << endl;
}


void inOrderUnRecur(Node* head)
{
    cout << "in-order: ";
    if(head != NULL)
    {
        stack<Node*> stack;
        while(!stack.empty() || head != NULL)
        {
            if(head != NULL)
            {
                stack.push(head);
                head = head->left;
            }
            else
            {
                head = stack.top();
                stack.pop();
                cout << head->value << " ";
                head = head->right;
            }
        }
    }
    cout << endl;
}


void posOrderUnRecur1(Node* head)
{
    cout << "pos-order: ";
    if(head != NULL)
    {
        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(head);
        while(!s1.empty())
        {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if(head->left != NULL)
            {
                s1.push(head->left);
            }
            if(head->right != NULL)
            {
                s1.push(head->right);
            }
        }
        while(!s2.empty())
        {
            cout << s2.top()->value << " ";
            s2.pop();
        }
    }
    cout << endl;
}


int main()
{
    Node* head = new Node(5);
    head->left = new Node(3);
    head->right = new Node(8);
    head->left->left = new Node(2);
    head->left->right = new Node(4);
    head->left->left->left = new Node(1);
    head->right->left = new Node(7);
    head->right->left->right = new Node(6);
    head->right->right = new Node(10);
    head->right->right->right = new Node(9);
    head->right->right->right = new Node(11);


    cout << "==============recursive=============" << endl;
    cout << "pre-order: ";
    preOrderRecur(head);
    cout << "in-order: ";
    inOrderRecur(head);
    cout << "pos-order: ";
    posOrderRecur(head);
    cout << endl;


    cout << "==============unrecursive=============" << endl;
    preOrderUnRecur(head);
    inOrderUnRecur(head);
    posOrderUnRecur1(head);

    return 0;
}
