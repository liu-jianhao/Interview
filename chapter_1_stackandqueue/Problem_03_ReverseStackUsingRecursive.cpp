#include <iostream>
#include <stack>

using namespace std;

static int getAndRemoveLastElement(stack<int>& stack)
{
    int result = stack.top();
    stack.pop();
    if(stack.empty())
    {
        return result;
    }
    else
    {
        int last = getAndRemoveLastElement(stack);
        stack.push(result);
        return last;
    }
}

static void reverse(stack<int>& stack)
{
    if(stack.empty())
    {
        return;
    }

    int i = getAndRemoveLastElement(stack);
    reverse(stack);
    stack.push(i);
}

int main()
{
    stack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    reverse(test);
    while(!test.empty())
    {
        cout << test.top() << endl;
        test.pop();
    }
    return 0;
}
