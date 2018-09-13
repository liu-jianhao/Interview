#include <iostream>
#include <vector>

using namespace std;

// 转圈打印一个子矩阵的外层
void printEdge(vector<vector<int>> m, int tR, int tC, int dR, int dC)
{
    // 只有一行
    if(tR == dR)
    {
        for(int i = tC; i <= dC; i++)
            cout << m[tR][i] + " ";
    }
    // 只有一列
    else if(tC == dC)
    {
        for(int i = tR; i <= dR; i++)
            cout << m[i][tC] + " ";
    }
    else
    {
        int curC = tC;
        int curR = tR;
        while(curC != dC)
        {
            cout << m[tR][curC] << " ";
            curC++;
        }
        while(curR != dR)
        {
            cout << m[curR][dC] << " ";
            curR++;
        }
        while(curC != tC)
        {
            cout << m[dR][curC] << " ";
            curC--;
        }
        while(curR != tR)
        {
            cout << m[curR][tC] << " ";
            curR--;
        }
    }
}

void spiralOrderPrint(vector<vector<int>> matrix)
{
    int tR = 0;
    int tC = 0;
    int dR = matrix.size() - 1;
    int dC = matrix[0].size() - 1;
    while(tR <= dR && tC <= dC)
    {
        printEdge(matrix, tR++, tC++, dR--, dC--);
    }
}

void printMatrix(vector<vector<int>> m)
{
    if(m.empty() || m[0].empty())
    {
        return;
    }

    for(unsigned int i = 0; i < m.size(); i++)
    {
        for(unsigned int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 },
        { 13, 14, 15, 16 } };
    printMatrix(matrix);
    cout << endl;
    spiralOrderPrint(matrix);
    return 0;
}
