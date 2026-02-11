#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> matrix(N+1);
    vector<vector<int>> DP(N+1, vector<int>(N+1,0));

    for (int i = 1; i <= N; ++i)
    {
        cin >> matrix[i].first >> matrix[i].second;
    }

    for (int len = 1; len < N; len++)
    {
        for (int i = 1; i <= N - len; ++i)
        {
            int j = i + len;
            DP[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = DP[i][k] + DP[k + 1][j] + (matrix[i].first * matrix[k].second * matrix[j].second);

                if (cost < DP[i][j]) DP[i][j] = cost;
            }
        }
    }

    cout << DP[1][N] << endl;
    return 0;
}