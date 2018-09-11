#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 16;
    int b = 111;
    cout << "a = " << a << "\tb = " << b << endl;
    swap(&a, &b);
    cout << "a = " << a << "\tb = " << b << endl;
}
