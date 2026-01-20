#include <iostream>
#include <vector>
#include <unordered_set>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

/*
ai + aj = x 를 만족하는 쌍을 구하는 프로그램을 작성하기

1 <= x <= 20만
1 <= n <= 10만 

n^2 으로 순회하면 풀수없다 시간초과.

hash로 값을 받는다.

1 2 3 5 7 9 10 11 12 로 정렬됨 


*/

int main()
{
	fastio();
	int n, x, ans =0;
	cin >> n;
	unordered_set<int> u_set;

	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		u_set.insert(k);
	}

	cin >> x;

	for (const auto& cur : u_set)
	{
		if (u_set.find(x - cur) != u_set.end())
		{
			ans++;
		}
	}

	cout << ans/2;
	return 0;
}