#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 1000000 까지 주어진다. 
	// 길이가 백만인 이진수의 갯수

	int N;
	cin >> N;

	// 0000
	// 0011
	// 1001
	// 1100
	// 1111

	/*
	1 : 1
	2 : 00 11
	3 : 001 100 111 
	4 : (0000 1100) [0011 1001 1111]
	*/

	vector<long long> dp(N+1, 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N] % 15746;
}