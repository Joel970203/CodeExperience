#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int main()
{
	int N;
	string T;
	cin >> N;
	cin >> T;

	unordered_map<char,int> alphabet;
	int left = 0;
	int ans = 0;
	int alpCnt = 0;
	for (int right = 0; right < (int)T.length(); right++)
	{
		if (alphabet[T[right]] == 0) alpCnt++;
		alphabet[T[right]]++;

		while (alpCnt > N)
		{
			alphabet[T[left]]--;
			if (alphabet[T[left]] == 0)
				alpCnt--;
			left++;
		}

		ans = max(ans, right - left + 1);
	}
	cout << ans;
}
