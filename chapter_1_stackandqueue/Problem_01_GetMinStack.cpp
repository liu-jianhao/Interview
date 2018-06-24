#include <iostream>
#include <stack>

using namespace std;

class MyStack1{
    private:
        stack<int> stackData;
        stack<int> stackMin;

    public:
        MyStack1(){}
        ~MyStack1(){}

        int top()
        {
            if(stackData.empty())
            {
                throw runtime_error("Your stack is empty.");
            }
            return stackData.top();
        }

        void pop()
        {
            if(stackData.empty())
            {
                throw runtime_error("Your stack is empty.");
            }
            int value = stackData.top();
            if(value == getMin())
            {
                stackMin.pop();
            }
            stackData.pop();
        }

        void push(int newNum)
        {
            if(stackMin.empty() || newNum <= getMin())
            {
                stackMin.push(newNum);
            }
            stackData.push(newNum);
        }

        int getMin()
        {
            return stackMin.top();
        }
};


class MyStack2{
    private:
        stack<int> stackData;
        stack<int> stackMin;

    public:
        MyStack2(){}
        ~MyStack2(){}

        int top()
        {
            if(stackData.empty())
            {
                throw runtime_error("Your stack is empty.");
            }
            return stackData.top();
        }

        void pop()
        {
            if(stackData.empty())
            {
                throw runtime_error("Your stack is empty.");
            }
            stackMin.pop();
            stackData.pop();
        }

        void push(int newNum)
        {
            if(stackMin.empty())
            {
                stackMin.push(newNum);
            }
            if(newNum <= getMin())
            {
                stackMin.push(newNum);
            }
            else
            {
                stackMin.push(getMin());
            }
            stackData.push(newNum);
        }

        int getMin()
        {
            return stackMin.top();
        }
};


int main()
{
    MyStack1 stack1;
    stack1.push(3);
    cout << stack1.getMin() << endl; //3
    stack1.push(4);
    cout << stack1.getMin() << endl; //3
    stack1.push(1);
    cout << stack1.getMin() << endl; //1
    cout << stack1.top() << endl;    //1
    stack1.pop();
    cout << stack1.getMin() << endl; //3


    cout << "===============" << endl;

    MyStack2 stack2;
    stack2.push(3);
    cout << stack2.getMin() << endl; //3
    stack2.push(4);
    cout << stack2.getMin() << endl; //3
    stack2.push(1);
    cout << stack2.getMin() << endl; //1
    cout << stack2.top() << endl;    //1
    stack2.pop();
    cout << stack2.getMin() << endl; //3

    return 0;
}
