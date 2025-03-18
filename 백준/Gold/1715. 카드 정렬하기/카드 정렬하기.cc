#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{

	/*
10 20 40
(10 20) 40 = 100
(10 40) 20 = 120
(20 40) 10  = 130

즉, 큰 숫자를 비교군에서 제일 적게 두고,
두개씩 구간 합을 계산해줘야한다.

묶음의 크기가 10^3 이고, 계산 최대는 10^5승 임으로, 10^8이니까
int로 처리가 가능하다.
*/

	int N, ans = 0;
	cin >> N;
	priority_queue<int,vector<int>,greater<>> pq;

	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		pq.push(k);
	}

	while (pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		int sum = (first + second);
		pq.push(sum);
		ans += sum;
	}

	cout << ans << endl;
	
} // 6 6 12 