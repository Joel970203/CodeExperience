#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N; 
    vector<int> P(N + 1); 
    vector<int> dp(N + 1, 0); 

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + P[j]);
        }
    }

    cout << dp[N] << endl; 
    return 0;
}