#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<long long> modCount(M, 0);
	long long prefixSum = 0;
	long long answer = 0;

	modCount[0] = 1;

	for (int i = 0; i < N; i++)
	{
		prefixSum += arr[i];
		int mod = prefixSum % M;

		answer += modCount[mod];

		modCount[mod]++;
	}

	cout << answer << '\n';
	return 0;
}
