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
    vector<int> wine(N + 1, 0);
    vector<int> DP(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> wine[i];
    }

    // 초기화
    DP[1] = wine[1];
    if (N > 1) DP[2] = wine[1] + wine[2];

    // 점화식 적용
    for (int i = 3; i <= N; i++)
    {
        DP[i] = max({ DP[i - 1], DP[i - 2] + wine[i], DP[i - 3] + wine[i - 1] + wine[i] });
    }

    // 결과 출력
    cout << DP[N] << endl;

    return 0;
}
