#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // dp[i][0]: i자리 이친수 중 마지막 자리가 0인 경우의 개수
    // dp[i][1]: i자리 이친수 중 마지막 자리가 1인 경우의 개수
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));

    // 초기 조건
    dp[1][0] = 0; // 1자리 수에 0으로 시작하는 이친수는 없음
    dp[1][1] = 1; // 1자리 수에 1로 시작하는 이친수는 1개

    // DP 테이블을 채우기
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; // 마지막 자리 0인 경우 // dp[2][0] = dp[1][0] + dp[1][1];
        dp[i][1] = dp[i - 1][0];               // 마지막 자리 1인 경우  // dp[2][1] = dp[1][0];
                                                                      // dp[3][0] = dp[2][0] + dp[2][1];
                                                                      // dp[3][1] = dp[2][0]
    }

    // 결과 출력
    long long result = dp[N][0] + dp[N][1];
    cout << result << endl;

    return 0;
}