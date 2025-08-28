#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

ll dp[501][501];
ll opt[501][501];
ll psum[501];

int main()
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            psum[i] = psum[i - 1] + a[i]; // 누적합
        }

        for (int i = 1; i <= N; i++)
        {
            dp[i][i] = 0;
            opt[i][i] = i;
        }

        for (int len = 2; len <= N; len++)
        {
            for (int i = 1; i + len - 1 <= N; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INF;

                int start = opt[i][j-1];
                int end = opt[i + 1][j];
                if (start < i) start = i;
                if (end > j - 1) end = j - 1;

                for (int k = start; k <= end; k++)
                {
                    ll cost = dp[i][k] + dp[k + 1][j] + (psum[j] - psum[i - 1]);
                    if (dp[i][j] > cost)
                    {
                        dp[i][j] = cost;
                        opt[i][j] = k;
                    }
                }

            }
        }

        cout << dp[1][N] << "\n";

        for (int i = 0; i <= N; i++) psum[i] = 0;
    }
}