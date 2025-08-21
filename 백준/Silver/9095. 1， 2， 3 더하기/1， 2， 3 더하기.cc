#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,k;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		vector<int> dp(k + 1);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= k; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}

		cout << dp[k] << endl;
	}

}