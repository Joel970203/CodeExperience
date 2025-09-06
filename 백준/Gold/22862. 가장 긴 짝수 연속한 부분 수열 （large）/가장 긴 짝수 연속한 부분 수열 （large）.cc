#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
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

	int ans = INT_MIN;
	int left = 0;
	int Kcnt = 0;
	int Ecnt = 0;

	for (int right = 0; right < N; right++)
	{
		if (arr[right] % 2 == 0)
		{
			Ecnt++;
		}

		else Kcnt++;

		while (Kcnt > K)
		{

			if (arr[left] % 2 == 0)
			{
				Ecnt--;
			}
			else
			{
				Kcnt--;
			}
			left++;
		}
		ans = max(ans, Ecnt);

	}

	cout << ans;
}