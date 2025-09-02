#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		if (arr.empty() || arr.back() < k)
		{
			arr.push_back(k);
			idx++;
		}

		else
		{
			*lower_bound(arr.begin(), arr.end(), k) = k;
		}
	}

	cout << arr.size() << endl;
}