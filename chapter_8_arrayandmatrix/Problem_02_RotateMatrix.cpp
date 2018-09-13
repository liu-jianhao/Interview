#include <iostream>
#include <vector>
using namespace std;

void rotateEdge(vector<vector<int>> &m, int tR, int tC, int dR, int dC)
{
    int times = dC - tC;
    int tmp = 0;
    for(int i = 0; i < times; i++)
    {
        tmp = m[tR][tC+i];
        m[tR][tC+i] = m[dR-i][tC];
        m[dR-i][tC] = m[dR][dC-i];
        m[dR][dC-i] = m[tR+i][dC];
        m[tR+i][dC] = tmp;
    }
}

void rotate(vector<vector<int>> &matrix)
{
    int tR = 0;
    int tC = 0;
    int dR = matrix.size()-1;
    int dC = matrix[0].size()-1;
    while(tR < dR)
    {
        rotateEdge(matrix, tR++, tC++, dR--, dC--);
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
    rotate(matrix);
    cout << "========================" << endl;
    printMatrix(matrix);
    return 0;
}
