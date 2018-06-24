#include <iostream>
#include <stack>

using namespace std;

static void sortStackByStack(stack<int>& myStack)
{
    stack<int> help;
    while(!myStack.empty())
    {
        int cur = myStack.top();
        myStack.pop();
        while(!help.empty() && help.top() < cur)
        {
            myStack.push(help.top());
            help.pop();
        }
        help.push(cur);
    }
    while(!help.empty())
    {
        myStack.push(help.top());
        help.pop();
    }
}

int main()
{
    stack<int> stack;
    stack.push(3);
    stack.push(1);
    stack.push(6);
    stack.push(2);
    stack.push(5);
    stack.push(4);
    sortStackByStack(stack);
    while(!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}
