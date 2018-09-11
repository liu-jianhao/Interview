#include <iostream>
using namespace std;

// 如果n为1返回0，n为0返回1
int flip(int n)
{
    return n ^ 1;
}

// 返回整数n的符号，整数或0返回1，负数则返回0
int sign(int n)
{
    return flip((n >> 31) & 1);
}

// 会有溢出问题
int getMax1(int a, int b)
{
    int c = a - b;
    int scA = sign(c);
    int scB = flip(scA);
    return a * scA + b * scB;
}

int getMax2(int a, int b)
{
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    int difSab = sa ^ sb;
    int sameSab = flip(difSab);
    int returnA = difSab * sa + sameSab * sc;
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}

int main()
{
    int a = -16;
    int b = 1;
    cout << "a = " << a << "\tb = " << b << endl;
    cout << getMax1(a, b) << endl;
    cout << getMax2(a, b) << endl;

    a = 2147483647;
    b = -2147480000;
    cout << "a = " << a << "\tb = " << b << endl;
    cout << getMax1(a, b) << endl;
    cout << getMax2(a, b) << endl;

    return 0;
}
