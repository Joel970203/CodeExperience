#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

bool visited[50][50] = { false };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int M, N;

void bfs(const vector<vector<int>> &graph,int y,int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int tempX = q.front().second;
		int tempY = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int curX = tempX + dx[i];
			int curY = tempY + dy[i];

			if (curX >= 0 && curX < M && curY >= 0 && curY < N)
			{
				if (!visited[curY][curX] && graph[curY][curX] == 1)
				{
					visited[curY][curX] = true;
					q.push({ curY,curX });
				}
			}
		}
	}
	return;
}

int main()
{
	int T,K, x, y;
	cin >> T;

	while (T--)
	{
		int cnt = 0;
		cin >> M >> N >> K;
		vector<vector<int>> graph(N, vector<int>(M, 0));
		memset(visited, 0, sizeof(visited));

		while (K--)
		{
			cin >> x >> y;
			graph[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (graph[i][j] == 1 && !visited[i][j])
				{
					bfs(graph,i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}

}