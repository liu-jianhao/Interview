#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int index1, int index2)
{
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void printArray(vector<int> arr)
{
    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void modify(vector<int>& arr)
{
    if(arr.empty() || arr.size() < 2)
    {
        return;
    }

    int even = 0;
    int odd = 1;
    int end = arr.size()-1;
    while(even <= end && odd <= end)
    {
        printArray(arr);
        if((arr[end] & 1) == 0)
        {
            swap(arr, end, even);
            even += 2;
        }
        else
        {
            swap(arr, end, odd);
            odd += 2;
        }
    }
}

int main()
{
    vector<int> arr = { 1, 8, 3, 2, 4, 6 };
    printArray(arr);
    modify(arr);
    printArray(arr);
    return 0;
}
