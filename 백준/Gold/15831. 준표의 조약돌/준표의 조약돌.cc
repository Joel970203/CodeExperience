#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, B, W;
	string T;
	
	cin >> N >> B >> W;
	cin >> T;

	int Bcnt = 0;
	int Wcnt = 0;

	int left = 0;
	int ans = 0;


	for (int right = 0; right < N; right++)
	{
		if (T[right] == 'W') Wcnt++;
		else Bcnt++;

		while (Bcnt > B)
		{
			if (T[left] == 'B') Bcnt--;
			else Wcnt--;
			
			left++;
		}

		if (Bcnt <= B && Wcnt >= W) ans = max(ans, right - left + 1);

	}

	cout << ans;
}