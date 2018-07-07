#include <iostream>
#include <map>
#include <vector>

using namespace std;

int merge(map<int, int> &mymap, int less, int more)
{
    int left = less - mymap[less] + 1;
    int right = more + mymap[more] - 1;
    int len = right - left + 1;
    mymap[left] = 2;
    mymap[right] = 2;
    return len;
}

int longestConsecutive(vector<int> arr)
{
    if(arr.empty())
    {
        return 0;
    }

    int mmax = 1;
    map<int, int> mymap;
    for(int i = 0; i < arr.size(); i++)
    {
        if(mymap.find(arr[i]) == mymap.end())
        {
            mymap.insert(pair<int, int>(arr[i], 1));
            if((mymap.find(arr[i]-1)) != mymap.end())
            {
                mmax = max(mmax, merge(mymap, arr[i]-1, arr[i]));
            }
            if(mymap.find(arr[i]+1) != mymap.end())
            {
                mmax = max(mmax, merge(mymap, arr[i], arr[i]+1));
            }
        }
    }
    return mmax;
}


int main()
{
    vector<int> arr = { 100, 4, 200, 1, 3, 2 };
    cout << longestConsecutive(arr) << endl;
    return 0;
}
