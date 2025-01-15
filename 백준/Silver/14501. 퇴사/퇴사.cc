#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main() {
    fastio();
    int N;
    cin >> N;

    vector<int> dp(N + 1, 0); // dp[i]는 i일에 끝나는 최대 이익을 저장합니다
    vector<pair<int, int>> consult(N + 1); // 상담의 기간과 이익을 저장합니다

    for (int i = 1; i <= N; ++i) {
        int Ti, Pi;
        cin >> Ti >> Pi;
        consult[i] = { Ti, Pi }; // consult[i]는 i일에 잡힌 상담의 기간과 이익
    }

    for (int i = 1; i <= N; ++i) {
        // 현재 상담을 받지 않고 이전까지의 최대 이익을 유지
        dp[i] = max(dp[i], dp[i - 1]);

        int Ti = consult[i].first;
        int Pi = consult[i].second;

        // 상담을 받을 수 있는 경우
        if (i + Ti - 1 <= N) {
            dp[i + Ti - 1] = max(dp[i + Ti - 1], dp[i - 1] + Pi);
        }
    }

    // 최종적으로 최대 이익은 dp[N]입니다
    cout << dp[N] << endl;

    return 0;
}
