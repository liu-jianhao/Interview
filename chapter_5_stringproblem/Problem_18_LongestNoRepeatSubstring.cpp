#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxUnique(string str)
{
    if(str.empty())
        return 0;
    vector<int> map(256, -1);
    int len = 0;
    int pre = -1;
    int cur = 0;
    for(unsigned int i = 0; i < str.size(); i++)
    {
        /* map[str[i]]表示str[i]最后一次出现的位置 */
        /* pre表示以str[i-1]结尾的最长子串的情况下，最长子串开始位置的前一个位置 */
        pre = max(pre, map[str[i]]);
        cur = i - pre;
        len = max(len, cur);
        map[str[i]] = i;
    }
    return len;
}

int main()
{
    string str = "aabaviddo";
    cout << str << endl;
    cout << maxUnique(str) << endl;
    return 0;
}
