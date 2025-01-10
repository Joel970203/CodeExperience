#include <iostream>
#include <vector>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;



int DP(int N)
{
	if (N == 1)
	{
		return 1;
	}

	else if (N == 2)
	{
		return 2;
	}

	else if (N == 3)
	{
		return 4;
	}

	else
	{
		return DP(N - 3) + DP(N - 2) + DP(N - 1);
	}

}

int main()
{
	fastio();
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << DP(N) << endl;
		
	}
}