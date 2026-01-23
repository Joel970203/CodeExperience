

/*
걷거나, 순간이동을 할 수있다.
동생을 찾을 수 있는 가장 빠른 시간이 몇초인가 ?
탐색 bfs 문제 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int mo[3] = { 1,-1,2 };
bool visited[100001] = { false };
int bfs(int start, int target)
{
	queue<pair<int, int>> q; // pos,time
	q.push({ start,0 });
	visited[start] = true;

	while (!q.empty())
	{
		int p = q.size();

		while (p--)
		{
			auto [pos, time] = q.front(); q.pop();

			if (pos == target) return time;
			for (int i = 0; i < 3; ++i)
			{
				int curPos, curTime;
				if (i == 2)
				{
					curPos = pos * 2;
				}

				else curPos = pos + mo[i];

				if (curPos<0 ||curPos > 100000 || visited[curPos]) continue;

				visited[curPos] = true;
				curTime = time + 1;
				q.push({ curPos,curTime });

			}
		}
	}
}

int main()
{
	cin >> N >> K;
	cout << bfs(N, K);
}