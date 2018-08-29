#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getMaxWindow(vector<int> arr, int w)
{
    vector<int> res(arr.size() - w + 1);
    if(arr.empty() || arr.size() < w)
    {
        return res;
    }

    queue<int> qmax; // 用来实现窗口最大值的更新
    int index = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        while(!qmax.empty() && arr[qmax.front()] <= arr[i])
        {
            qmax.pop();
        }
        qmax.push(i);
        if(qmax.front() == i - w)
        {
            qmax.pop();
        }
        if(i >= w - 1)
        {
            res[index++] = arr[qmax.front()];
        }
    }
    return res;
}

void printArray(vector<int> arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = { 4, 3, 5, 4, 3, 3, 6, 7 };
    int w = 3;
    printArray(getMaxWindow(arr, w)); // 5 5 5 4 6 7
}
