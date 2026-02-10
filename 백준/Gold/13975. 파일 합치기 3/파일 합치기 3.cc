#include <iostream>
#include <vector>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;

int main()
{
	fastio();
	int T, K;
	cin >> T;


	while (T--)
	{
		cin >> K;
		vector<int> arr(K);
		priority_queue<ll, vector<ll>, greater<ll>> pq;

		for (int i = 0; i < K; ++i)
		{
			int t;
			cin >> t;
			pq.push(t);
		}

		ll ans = 0;

		while (pq.size() > 1)
		{
			ll first = pq.top(); pq.pop();
			ll second = pq.top(); pq.pop();
			ll res = first + second;
			ans += res;
			pq.push(res);
		}

		cout << ans << endl;
	}

	return 0;



}