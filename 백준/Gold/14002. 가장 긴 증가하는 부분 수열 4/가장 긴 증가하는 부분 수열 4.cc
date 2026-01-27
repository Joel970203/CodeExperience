#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> DP(N, 1);
	vector<int> parent(N, -1);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int max_len = 0;
	int last_idx = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && DP[i] < DP[j]+1)
			{
				DP[i] = DP[j] + 1;
				parent[i] = j;
			}
		}

		if (DP[i] > max_len)
		{
			max_len = DP[i];
			last_idx = i;
		}
	}

	cout << max_len << "\n";

	vector<int> path;
	for (int i = last_idx; i != -1; i = parent[i]) {
		path.push_back(arr[i]);
	}

	reverse(path.begin(), path.end());
	for (int val : path) cout << val << " ";

	return 0;
}