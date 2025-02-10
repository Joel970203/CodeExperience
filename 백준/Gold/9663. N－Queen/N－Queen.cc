#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, result = 0;
vector<int> column(15);  // column[i]는 i행에서 퀸이 위치한 열 인덱스

bool isValid(int row)
{
    for (int i = 0; i < row; i++)
    {
        if (column[i] == column[row] || abs(column[i] - column[row]) == abs(i - row))
            return false;
    }
    return true;
}

void solve(int row)
{
    if (row == N)
    {
        result++;
        return;
    }

    for (int col = 0; col < N; col++)
    {
        column[row] = col;
        if (isValid(row))
        {
            solve(row + 1);
        }
    }
}

int main()
{
    cin >> N;
    solve(0);
    cout << result << "\n";
    return 0;
}
