#include <iostream>
#include <vector>

using namespace std;

int minPathSum1(vector<vector<int>> m)
{
    if(m.empty() || m[0].empty())
        return 0;


    int row = m.size();
    int col = m[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    dp[0][0] = m[0][0];
    for(int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i-1][0] + m[i][0];
    }
    for(int j = 1; j < row; j++)
    {
        dp[0][j] = dp[0][j-1] + m[0][j];
    }

    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + m[i][j];
        }
    }
    return dp[row-1][col-1];
}

void prinrMatrix(vector<vector<int>> matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> m = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, {5, 0, 6, 1} ,
        { 8, 8, 4, 0 } };
    prinrMatrix(m);
    cout << minPathSum1(m) << endl;
    return 0;
}
