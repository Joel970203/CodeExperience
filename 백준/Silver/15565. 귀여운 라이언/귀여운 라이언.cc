#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int ans = 1e9;
	int cnt = 0;
	int left = 0;
	for (int right = 0; right < N; right++)
	{
		if (arr[right] == 1) cnt++;

		while (cnt >= K)
		{
			ans = min(ans, right - left + 1);
			if (arr[left] == 1) cnt--;
			left++;
		}
	}

	if (ans == 1e9) cout << -1;
	else cout << ans;
}