#include <iostream>
using namespace std;

int getGCD(int a, int b) 
{
	while (b != 0) 
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int getLCM(int a, int b) 
{
	return a * b / getGCD(a, b);
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int lcm = getLCM(M, N);
		int cnt = -1;

		for (int i = x; i <= lcm; i += M) 
		{
			if ((i - 1) % N + 1 == y)
			{
				cnt = i;
				break;
			}
		}

		cout << cnt << endl;
	}
}
