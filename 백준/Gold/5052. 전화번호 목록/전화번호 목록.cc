#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
	/*
	50번 * 10&8 * 10  
	*/
	fastio();
	int t, n;
	bool shift;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<string> arr(n);
		shift = true;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n-1; i++)
		{
			if (arr[i + 1].substr(0,arr[i].size()) == arr[i])
			{
				shift = false;
				break;
			}

		}

		if (shift) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}