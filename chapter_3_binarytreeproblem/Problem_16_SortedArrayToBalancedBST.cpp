#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int data)
    {
        value = data;
    }
};

Node* generate(vector<int> sortArr, int start, int end)
{
    if(start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* head = new Node(sortArr[mid]);
    head->left = generate(sortArr, start, mid-1);
    head->right = generate(sortArr, mid+1, end);
    return head;
}

Node* generateTree(vector<int> sortArr)
{
    if(sortArr.empty())
        return NULL;

    return generate(sortArr, 0, sortArr.size()-1);
}

string getSpace(int num)
{
    string space = " ";
    string buf;
    for(int i = 0; i < num; i++)
    {
        buf += " ";
    }
    return buf;
}

void printInOrder(Node* head, int height, string to, int len)
{
    if(head == NULL)
        return;

    printInOrder(head->right, height+1, "v", len);
    char *temp = (char*)malloc(sizeof(char*));
    sprintf(temp, "%d", head->value);
    string value(temp);
    string val = to + value + to;
    int lenM = val.size();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val << endl;
    printInOrder(head->left, height+1, "^", len);
}

void printTree(Node* head)
{
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}

int main()
{
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printTree(generateTree(arr));
    return 0;
}
