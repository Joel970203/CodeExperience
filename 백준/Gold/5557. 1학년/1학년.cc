#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long DP[101][21] = { 0 }; // y번까지 살펴보았을떄 답이 x인것의 갯수
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	DP[0][arr[0]] = 1; // 맨처음에 , 맨처음변수까지 체크한건 1개 있음 

	for (int i = 1; i < N - 1; i++)
	{
		for (int val = 0; val <= 20; val++)
		{
			if (DP[i-1][val] > 0) // i 까지 체크했는데 val 값이 존재한다면,
			{
				if (val + arr[i] <= 20)  DP[i][val + arr[i]] += DP[i - 1][val];
				if (val - arr[i] >= 0) DP[i][val - arr[i]] += DP[i - 1][val];
			}
		}
	}

	cout << DP[N-2][arr[N - 1]] << endl;
}