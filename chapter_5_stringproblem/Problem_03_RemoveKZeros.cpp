#include <iostream>
#include <string>

using namespace std;

string removeKZeros(string str, int k)
{
    if(str.empty() || k < 1)
        return str;

    int count = 0, start = -1;
    for(unsigned int i = 0; i < str.size(); i++)
    {
        if(str[i] == '0')
        {
            count++;
            start = start == -1 ? i : start;
        }
        else
        {
            if(count == k)
            {
                while(count-- != 0)
                    str[start++] = 0;   //赋值0就是删除
            }
            count = 0;
            start = -1;
        }
    }

    if(count == k)
    {
        while(count-- != 0)
            str[start++] = 0;
    }

    return str;
}

int main()
{
    string test1 = "0A0B0C00D0";
    cout << removeKZeros(test1, 1) << endl;


    string test2 = "00A00B0C00D0";
    cout << removeKZeros(test2, 2) << endl;

    string test3 = "000A00B000C0D00";
    cout << removeKZeros(test3, 3) << endl;

    string test4 = "0000A0000B00C000D0000";
    cout << removeKZeros(test3, 4) << endl;

    string test5 = "00000000";
    cout << removeKZeros(test5, 5) << endl;

    return 0;
}
