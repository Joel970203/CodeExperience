#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
// 2:55 풀이 시작

int BFS(int N, int K)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0,N }); // cost,loc
	bool visited[100001] = { false };
	visited[N] = true;

	while (!pq.empty())
	{
		int time = pq.top().first; 
		int pos = pq.top().second;
		pq.pop();

		if (pos == K)
		{
			return time;
		}

		for (int i=0;i<3;i++)
		{
			if (i == 0)
			{
				int newpos = pos * 2;
				if (newpos >= 0 && newpos <= 100000)
				{
					if (visited[newpos] == false)
					{
						visited[newpos] = true;
						pq.push({ time,newpos });
					}
				}
			}
			else if (i == 1)
			{
				int newpos = pos +1;
				if (newpos >= 0 && newpos <= 100000)
				{
					if (visited[newpos] == false)
					{
						visited[newpos] = true;
						pq.push({ time+1,newpos });
					}
				}
			}
			else if (i == 2)
			{
				int newpos = pos -1;
				if (newpos >= 0 && newpos <= 100000)
				{
					if (visited[newpos] == false)
					{
						visited[newpos] = true;
						pq.push({ time+1,newpos });
					}
				}
			}
		}
	}
}
int main()
{
	/*
	입력처리 N,K 
	졔약 조건, 100000 -> N 타임에 풀것
	
	수빈 위치 N
	동생위치 K 
	-> BFS XXXXX

	이 문제는 가중치가 0과 1이 존재하기 떄문에, 기존 BFS로는 최단이 보장되지않는다.
	*/

	int N, K;
	cin >> N >> K;
	cout << BFS(N, K);
}