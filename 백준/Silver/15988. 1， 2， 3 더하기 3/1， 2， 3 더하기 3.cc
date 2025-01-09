#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int main()
{
    int T;
    cin >> T;

    vector<int> test_cases(T);
    int max_n = 0;

    for (int i = 0; i < T; i++) 
    {
        cin >> test_cases[i];
        if (test_cases[i] > max_n) 
        {
            max_n = test_cases[i];
        }
    }

    vector<long long> dp(max_n + 1);
    dp[0] = 1; 
    if (max_n >= 1) dp[1] = 1;
    if (max_n >= 2) dp[2] = 2;
    if (max_n >= 3) dp[3] = 4;

    for (int i = 4; i <= max_n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }

    for (int i = 0; i < T; i++) 
    {
        cout << dp[test_cases[i]] << endl;
    }

    return 0;
}
