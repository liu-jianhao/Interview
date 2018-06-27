#include <iostream>
#include <string>

using namespace std;

void replace(string& chas)
{
    if(chas.empty())
    {
        return;
    }

    int num = 0;
    int length = chas.size();
    for(int i = 0; i < length; i++)
    {
        if(chas[i] == ' ')
            num++;
    }

    int j = length + 2 * num - 1;
    chas.resize(j); //不然后面的数据会缺失
    for(int i = length-1; i > -1; i--)
    {
        if(chas[i] != ' ')
        {
            chas[j--] = chas[i];
        }
        else
        {
            chas[j--] = '0';
            chas[j--] = '2';
            chas[j--] = '%';
        }
    }
}

void modify(string& chas)
{
    if(chas.empty())
        return;

    int j = chas.size() - 1;
    for(int i = chas.size()-1; i > -1; i--)
    {
        if(chas[i] != '*')
        {
            chas[j--] = chas[i];
        }
    }

    for(; j > -1; )
    {
        chas[j--] = '*';
    }
}

int main()
{
    string chas1 = "a b  c00000000";
    cout << chas1 << endl;
    replace(chas1);
    cout << chas1 << endl;

    string chas2 = "12**345";
    cout << chas2 << endl;
    modify(chas2);
    cout << chas2 << endl;
    return 0;
}
