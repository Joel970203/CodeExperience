#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 
using namespace std;

int main() 
{
    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> cities(N); 
    for (int i = 0; i < N; i++) 
    {
        cin >> cities[i].first >> cities[i].second;
    }

    
    vector<int> dp(C + 101, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) 
    {
        int cost = cities[i].first;
        int customers = cities[i].second;

        for (int j = customers; j < dp.size(); j++) 
        {
            dp[j] = min(dp[j], dp[j - customers] + cost);
        }
    }

    int result = INF;
    for (int i = C; i < dp.size(); i++) 
    {
        result = min(result, dp[i]);
    }

    cout << result << endl;
}