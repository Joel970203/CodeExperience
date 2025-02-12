#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<pair<int, int>> list(N);
	vector<int> dp(K + 1, 0);
	for (int i = 0; i < N; i++) 
	{
		int W, V;
		cin >> W >> V;
		list[i].first = W;
		list[i].second = V;
	}
	
	sort(list.begin(), list.end());

	
	for (int i = 0; i < N; i++)
	{
		int W = list[i].first; // 무게
		int V = list[i].second; // 가치 

		for (int j = K; j >= W; j--)
		{
			dp[j] = max(dp[j], dp[j - W] + V);
		}

	}
	
	cout << dp[K] << endl;  
}