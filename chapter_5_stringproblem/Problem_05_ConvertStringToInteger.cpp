#include <iostream>
#include <string>
#include <limits.h>


using namespace std;

bool isValid(string chas)
{
    if(chas[0] != '-' && chas[0] < '0' || chas[0] > '9')
    {
        return false;
    }
    if(chas[0] == '-' && (chas.size() == 1 || chas[1] == '0'))
    {
        return false;
    }
    if(chas[0] == '0' && chas.size() > 1)
    {
        return false;
    }
    for(int i = 1; i < chas.size(); i++)
    {
        if(chas[i] < '0' || chas[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int convert(string str)
{
    if(str.empty())
    {
        return 0;
    }

    if(!isValid(str))
    {
        return 0;
    }

    bool posi = str[0] == '-' ? false : true;
    int minq = INT_MIN / 10;
    int minr = INT_MIN % 10;
    int res = 0;
    int cur = 0;
    for(int i = posi ? 0 : 1; i < str.size(); i++)
    {
        cur = '0' - str[i];
        if((res < minq) || (res == minq && cur < minr))
        {
            return 0;
        }
        res = res * 10 + cur;
    }

    if(posi && res == INT_MIN)
        return 0;

    return posi ? -res : res;
}

int main()
{
    string test1 = "2147483647";
    cout << convert(test1) << endl;

    string test2 = "-2147483648";
    cout << convert(test2) << endl;

    string test3 = "2147483648";
    cout << convert(test3) << endl;

    string test4 = "-2147483649";
    cout << convert(test4) << endl;

    string test5 = "-123";
    cout << convert(test5) << endl;

    return 0;
}
