#include <iostream>
#include <vector>
using namespace std;

// 遇到不同的就“跳”
void sort1(vector<int>& arr)
{
    int tmp = 0;
    int next = 0;
    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        tmp = arr[i];
        while(arr[i] != i+1)
        {
            next = arr[tmp-1];
            arr[tmp-1] = tmp;
            tmp = next;
        }
    }
}

// 交换的方式
void sort2(vector<int>& arr)
{
    int tmp = 0;
    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        while(arr[i] != i+1)
        {
            tmp = arr[arr[i]-1];
            arr[arr[i]-1] = arr[i];
            arr[i] = tmp;
        }
    }
}

void printArray(vector<int> arr)
{
    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = { 8, 2, 1, 6, 3, 7, 5, 4 };
    sort1(arr1);
    printArray(arr1);

    vector<int> arr2 = { 8, 2, 1, 6, 3, 7, 5, 4 };
    sort2(arr2);
    printArray(arr2);
    return 0;
}
