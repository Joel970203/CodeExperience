#include <iostream>
#include <vector>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;


int dx[3] = { +1,-1,2 };
vector<vector<bool>> visited(500001, vector<bool>(2, false));


void bfs(int x, int goal)
{
	queue<pair<int, int>> q; // 위치, 시간
	q.push(make_pair(x, 0));
	visited[x][0] = true;

	int t = 0;

	while (!q.empty())
	{
		int dest = goal + t * (t + 1) / 2; 
		if (dest > 500000) break;

		if (visited[dest][t % 2])
		{
			cout << t << "\n";
			return;
		}

		int qSize = q.size();
		while (qSize--)
		{
			pair<int, int> front = q.front();
			q.pop();
			int temp = front.first;
			int Time = front.second;

			for (int i = 0; i < 3; i++)
			{
				int next;
				if (i < 2) next = temp + dx[i];
				else       next = temp * dx[i];

				if (0 <= next && next <= 500000 && !visited[next][(t + 1) % 2])
				{
					visited[next][(t + 1) % 2] = true;
					q.push({ next, t + 1 });
				}
			}
		}

		t++; 
	}

	cout << -1 << "\n";
}

int main()
{
	fastio();
	int N, K;
	cin >> N >> K;

	if (N == K)
	{
		cout << 0 << "\n";
		return 0;
	}
	vector<int> dp(500000, 0);

	bfs(N, K);
}