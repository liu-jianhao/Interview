#include <iostream>
#include <string>

using namespace std;

bool isRotation(string a, string b)
{
    if(a.empty() || b.empty() || a.size() != b.size())
    {
        return false;
    }

    string b2 = b+b;
    ssize_t res = b2.find(a);
    if(res == -1)
    {
        return false;
    }
    return true;
}

int main()
{
    string str1 = "yunzuocheng";
    string str2 = "zuochengyun";
    cout << isRotation(str1, str2) << endl;
}
