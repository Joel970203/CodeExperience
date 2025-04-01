#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int k)
{
	if (k < 2) return false;
	if (k == 2) return true;
	if (k % 2 == 0) return false;

	for (int i = 3; i * i <= k; i += 2)
	{
		if (k % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}

		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (isPrime(i))
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
