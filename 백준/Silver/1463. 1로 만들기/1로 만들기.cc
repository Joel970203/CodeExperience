#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> DP(N + 1, 0);

	for (int i = N-1; i >= 1; i--)
	{
		if (i * 3 <= N)
		{
			DP[i] = min(DP[i+1],min(DP[i * 3], DP[i * 2]))+1;
		}

		else if (i * 2 <= N)
		{
			DP[i] = min(DP[i * 2], DP[i + 1]) + 1;
		}

		else
			DP[i] = DP[i + 1] + 1;
	}

	cout << DP[1] << endl;
}