#include <iostream>
#include <stack>
using namespace std;

class TwoStacksQueue {
    private:
        stack<int> stackPush;
        stack<int> stackPop;

    public:
        TwoStacksQueue(){};
        ~TwoStacksQueue(){};

        // C++的queue和Java的不太一样
        // C++的pop操作只删除不返回值
        void push(int pushInt);
        void pop();
        int front();
};

void TwoStacksQueue::push(int pushInt)
{
    stackPush.push(pushInt);
}

void TwoStacksQueue::pop()
{
    if(stackPop.empty() && stackPush.empty())
    {
        throw "Queue is empty!";
    }
    else if(stackPop.empty())
    {
        while(!stackPush.empty())
        {
            int temp = stackPush.top();
            stackPush.pop();
            stackPop.push(temp);
        }
    }
    stackPop.pop();
}

int TwoStacksQueue::front()
{
    if(stackPop.empty() && stackPush.empty())
    {
        throw "Queue is empty!";
    }
    else if(stackPop.empty())
    {
        while(!stackPush.empty())
        {
            int temp = stackPush.top();
            stackPush.pop();
            stackPop.push(temp);
        }
    }
    return stackPop.top();
}

int main()
{
    TwoStacksQueue test;
    test.push(1);
    test.push(2);
    test.push(3);
    cout << test.front() << endl; // 1
    test.pop();
    cout << test.front() << endl; // 2
    test.pop();
    cout << test.front() << endl; // 3
    test.pop();
    return 0;
}
