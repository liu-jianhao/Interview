#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int minDistance(vector<string> strs, string str1, string str2)
{
    if(str1.empty() || str2.empty())
    {
        return -1;
    }

    if(str1 == str2)
    {
        return 0;
    }

    int last1 = -1;
    int last2 = -1;
    int mmin = INT_MAX;
    for(int i = 0; i < strs.size(); i++)
    {
        if(strs[i] == str1)
        {
            mmin = min(mmin, last2 == -1 ? mmin : i - last2);
            last1 = i;
        }
        if(strs[i] == str2)
        {
            mmin = min(mmin, last1 == -1 ? mmin : i - last1);
            last2 = i;
        }
    }
    return mmin == INT_MAX ? -1 : mmin;
}

int main()
{
    vector<string> strArr = {"4", "2", "2", "3", "2", "2", "3",
                                "1", "1", "3"};

    cout << minDistance(strArr, "4", "3") << endl;
    cout << minDistance(strArr, "2", "3") << endl;
    cout << minDistance(strArr, "2", "1") << endl;
}
