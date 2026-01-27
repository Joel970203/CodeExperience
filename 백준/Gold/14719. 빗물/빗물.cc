#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() 
{
	int W, H;
	cin >> H >> W;

	int ans = 0;

	vector<int> arr(W);

	for (int i = 0; i < W; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < W-1; ++i)
	{
		int l_height = INT_MIN;
		int r_height = INT_MIN;
		int height = INT_MAX;
		int k = arr[i];

		for (int j = i; j >= 0; j--)
		{
			l_height = max(l_height, arr[j]);
		}

		for (int j = i; j < W; j++)
		{
			r_height = max(r_height, arr[j]);
		}

		height = min(r_height, l_height);
		
		if (height > k)
		{
			ans += height - k;
		}
	}

	cout << ans;
	return 0;
}