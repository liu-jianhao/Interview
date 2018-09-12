#include <iostream>
#include <vector>
using namespace std;

vector<int> getKSysNumFromNum(int value, int k)
{
    vector<int> res(32, 0);
    int index = 0;
    while(value != 0)
    {
        res[index++] = value % k;
        value /= k;
    }
    return res;
}

void setExclusiveOr(vector<int> &e0, int value, int k)
{
    vector<int> curKSysNum = getKSysNumFromNum(value, k);
    for(unsigned int i = 0; i != e0.size(); i++)
    {
        e0[i] = (e0[i] + curKSysNum[i]) % k;
    }
}

int getNumFromKSysNum(vector<int> &e0, int k)
{
    int res = 0;
    for(int i = e0.size()-1; i != -1; i--)
    {
        res = res * k + e0[i];
    }
    return res;
}

int onceNum(vector<int> &arr, int k)
{
    vector<int> e0(32, 0);
    for(unsigned int i = 0; i < arr.size(); i++)
    {
        setExclusiveOr(e0, arr[i], k);
    }
    int res = getNumFromKSysNum(e0, k);
    return res;
}

int main()
{
    vector<int> test1 = { 1, 1, 1, 2, 6, 6, 2, 2, 10, 10, 10, 12, 12, 12, 6, 9 };
    cout << onceNum(test1, 3) << endl;

    vector<int> test2 = { -1, -1, -1, -1, -1, 2, 2, 2, 4, 2, 2 };
    cout << onceNum(test2, 5) << endl;
    return 0;
}
