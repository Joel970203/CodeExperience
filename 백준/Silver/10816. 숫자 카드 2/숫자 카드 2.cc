#include <iostream>
#include <vector>
#include <unordered_map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
	fastio();
	int N, M;
	unordered_map<int,int> arr1;
	vector<int> arr2;
	cin >> N;
	while (N--)
	{
		int k;
		cin >> k;
		arr1[k]++;
	}

	cin >> M;

	while (M--)
	{
		int k;
		cin >> k;
		if (arr1.find(k) != arr1.end())
		{
			cout << arr1[k] << " ";
		}

		else cout << 0 << " ";
	}

	return 0;
}