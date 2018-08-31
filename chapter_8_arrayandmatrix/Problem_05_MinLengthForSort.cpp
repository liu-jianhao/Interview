#include <iostream>
#include <vector>

using namespace std;

int getMinLength(vector<int> arr)
{
    if(arr.size() < 2)
        return 0;

    int mmin = arr[arr.size()-1];
    int noMinIndex = -1;
    for(unsigned int i = arr.size() - 2; i > 0; i--)
    {
        if(arr[i] > mmin)
        {
            noMinIndex = i;
        }
        else
        {
            mmin = min(mmin, arr[i]);
        }
    }

    if(noMinIndex == -1)
        return 0;

    int mmax = arr[0];
    int noMaxIndex = -1;
    for(unsigned int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < mmax)
        {
            noMaxIndex = i;
        }
        else
        {
            mmax = max(mmax, arr[i]);
        }
    }

    return noMaxIndex - noMinIndex + 1;
}

int main()
{
    vector<int> arr = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
    cout << getMinLength(arr) << endl;
    return 0;
}
