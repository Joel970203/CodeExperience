#include <iostream>
#include <queue>
#include <unordered_map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;


/*
n^2 이면 10^12 이라 넘어간다.

i를 만났을때, 나는 이 배열에서 j번쨰로 큰 아이입니다 
라고 알 수 있어야함.

즉 순서.. ?


             
*/
int main()
{
	int N;
	cin >> N;
	vector<int> arr;
	priority_queue<int,vector<int>,greater<>> pq;
	unordered_map<int, int> map;
	while (N--)
	{
		int k;
		cin >> k;
		arr.push_back(k);
		pq.push(k);
	}


	int temp;
	int cur = pq.top();
	int cnt = 0;
	map[cur] = cnt;
	pq.pop();


	while (!pq.empty())
	{
		int temp = pq.top();
		if (temp == cur)
		{
			map[temp] = cnt;
		}

		else
		{
			cnt++;
			map[temp] = cnt;
		}

		cur = temp;
		pq.pop();
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << map[arr[i]] << " ";
	}

	return 0;
}