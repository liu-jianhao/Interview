#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDeformation(string str1, string str2)
{
    if(str1.size() != str2.size())
        return false;

    vector<int> map(256);
    for(unsigned int i = 0; i < str1.size(); i++)
    {
        map[str1[i]]++;
    }
    for(unsigned int i = 0; i < str2.size(); i++)
    {
        if(map[str2[i]]-- == 0)
            return false;
    }

    return true;
}

int main()
{
    string A = "abcabcabc";
    string B = "bcacbaacb";
    cout << isDeformation(A, B);
    cout << endl;


    A = "abcabaabc";
    B = "bcacbaacb";
    cout << isDeformation(A, B);
    return 0;
}
