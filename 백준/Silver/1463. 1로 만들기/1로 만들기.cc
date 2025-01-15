#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main() {
    fastio();
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0);

    for (int i = 2; i <= N; ++i) {
        // 기본적으로 i-1을 계산
        dp[i] = dp[i - 1] + 1;
        // i가 2로 나누어 떨어지면
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        // i가 3으로 나누어 떨어지면
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[N] << endl;
    return 0;
}