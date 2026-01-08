#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, answer = 0;
	string k;
	cin >> n;

	while (n--)
	{
		cin >> k;
		int m = k.length();
		vector<bool> chk(26, false);
		bool found = true;
		for (int i = 0; i < m; i++)
		{
			if (chk[k[i] - 'a'] == true)
			{
				if (k[i - 1] != k[i])
				{
					found = false;
					break;
				}
			}

			else
			{
				chk[k[i] - 'a'] = true;
			}
		}

		if (found) answer++;
	}

	cout << answer;
	return 0;
}