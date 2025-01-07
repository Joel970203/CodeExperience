#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(k + 1, 10001); // k + 1 크기의 dp 배열을 10001로 초기화 (최댓값)
    dp[0] = 0; 

    // 동전의 값을 하나씩 확인
    for (int i = 0; i < n; i++) 
    {
        for (int j = coins[i]; j <= k; j++) 
        {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    if (dp[k] == 10001) {
        cout << -1 << endl; // 불가능한 경우
    }
    else {
        cout << dp[k] << endl;
    }

    return 0;
}
