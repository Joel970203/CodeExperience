#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

int main() {
    int N;
    cin >> N;

    // dp[i][j]: 길이가 i이고 마지막 숫자가 j인 계단 수의 개수
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

    // 길이가 1일 때 초기화
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    // DP 테이블 채우기
    for (int length = 2; length <= N; length++) {
        for (int digit = 0; digit <= 9; digit++) {
            if (digit > 0) { // 1~9
                dp[length][digit] += dp[length - 1][digit - 1]; 
            }
            if (digit < 9) { // 0~8
                dp[length][digit] += dp[length - 1][digit + 1];
            }
            dp[length][digit] %= MOD;  
        }
    }

    long long result = 0;
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[N][i]) % MOD;
    }

    cout << result << endl;
    return 0;
}