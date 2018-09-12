#include <iostream>
#include <vector>
using namespace std;

// 找出一个出现奇数次的数
void printOddTimesNum1(vector<int> arr)
{
    int e0 = 0;
    for(int cur : arr)
    {
        e0 ^= cur;
    }
    cout << e0 << endl;
}

// 找出两个个出现奇数次的数
void printOddTimesNum2(vector<int> arr)
{
    int e0 = 0, e0hasOne = 0;
    for(int cur : arr)
    {
        e0 ^= cur;
    }

    int rightOne = e0 & (~e0 + 1);
    for(int cur : arr)
    {
        if((cur & rightOne) != 0)
        {
            e0hasOne ^= cur;
        }
    }
    cout << e0hasOne << " " << (e0 ^ e0hasOne) << endl;
}

int main(){
    vector<int> arr1 = { 3, 3, 2, 3, 1, 1, 1, 3, 1, 1, 1 };
    printOddTimesNum1(arr1);

    vector<int> arr2 = { 4, 3, 4, 2, 2, 2, 4, 1, 1, 1, 3, 3, 1, 1, 1 ,4, 2, 2 };
    printOddTimesNum2(arr2);

    return 0;
}
