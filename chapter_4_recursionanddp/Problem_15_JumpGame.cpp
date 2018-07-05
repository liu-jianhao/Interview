#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> arr)
{
    if(arr.empty())
        return 0;

    int jump = 0;
    int cur = 0;
    int next = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(cur < i)
        {
            jump++;
            cur = next;
        }
        next = max(next, i + arr[i]);
    }
    return jump;
}

int main()
{
    vector<int> arr = { 3, 2, 3, 1, 1, 4 };
    cout << jump(arr) << endl;
    return 0;
}
