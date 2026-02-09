#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<pair<int, int>> arr;
	vector<int> DP(K+1, 0);
	for (int i = 0; i < N; ++i)
	{
		int W, V;
		cin >> W >> V;
		arr.push_back({ W,V });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; ++i)
	{
		int W = arr[i].first;
		int V = arr[i].second;

		for (int j = K; j >= W; j--)
		{
			DP[j] = max(DP[j], DP[j - W] + V);

		}
	}

	cout << DP[K];
}