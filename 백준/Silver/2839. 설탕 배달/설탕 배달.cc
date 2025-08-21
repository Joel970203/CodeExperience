#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<int> dp(N + 1, 1e9);
    dp[3] = 1;
    if (N >= 5) dp[5] = 1;

    for (int i = 6; i <= N; i++) 
    {
        if (dp[i - 3] != 1e9) dp[i] = min(dp[i], dp[i - 3] + 1);
        if (dp[i - 5] != 1e9) dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    if (dp[N] == 1e9) cout << -1;
    else cout << dp[N];

    return 0;
}
