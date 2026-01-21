#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	// 이건 슬라이딩 윈도우 
	cin >> N >> M;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		/*
		정답일때,
		값이 넘어갈때,
		부족할때
		*/
		sum += arr[i];


		while (sum > M)
		{
			sum -= arr[start];
			start++;
			if (sum <= M)
			{
				break;
			}
		}


		if (sum == M)
		{
			ans++;
		}
	}

	cout << ans;
	return 0;
}