#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main()
{
    fastio();
    int N;
    cin >> N;

    vector<int> R(N), G(N), B(N);
    vector<vector<int>> DP(N, vector<int>(3, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> R[i] >> G[i] >> B[i];
    }

    // 초기화
    DP[0][0] = R[0];
    DP[0][1] = G[0];
    DP[0][2] = B[0];

    for (int i = 1; i < N; i++)
    {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + R[i]; // 첫 번째 집을 빨강으로 칠하는 비용
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + G[i]; // 첫 번째 집을 초록으로 칠하는 비용
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + B[i]; // 첫 번째 집을 파랑으로 칠하는 비용
    }

    // 마지막 집까지의 최소 비용
    int result = min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2] });
    cout << result << endl;

    return 0;
}