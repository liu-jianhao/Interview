#include <iostream>
using namespace std;

// 不能是负数，否则会无限循环
int count1(int n)
{
    int res = 0;
    while(n != 0)
    {
        res += n & 1;
        n >>= 1;
    }
    return res;
}

int count2(int n)
{
    int res = 0;
    while(n != 0)
    {
        n &= (n-1);
        res++;
    }
    return res;
}

int count3(int n) {
    int res = 0;
    while (n != 0) {
        n -= n & (~n + 1);
        res++;
    }
    return res;
}

int count4(int n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}


void printNumBit(int n)
{
    for(int i = 31; i != -1; i--)
    {
        if((n & (1 << i)) != 0) {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << endl;
}



int main(){
    int num = -1;
    printNumBit(num);

    /* cout << count1(num) << endl; */
    cout << count2(num) << endl;
    cout << count3(num) << endl;
    cout << count4(num) << endl;
    printNumBit(0x55555555);
    printNumBit(0x33333333);
    printNumBit(0x0f0f0f0f);
    printNumBit(0x00ff00ff);
    printNumBit(0x0000ffff);

    return 0;
}
