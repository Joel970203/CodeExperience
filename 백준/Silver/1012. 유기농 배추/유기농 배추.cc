#include <iostream>
#include <queue>
#include <cstring>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;
int T, M, N, K, x, y;
int farm[50][50];
int visited[50][50];
queue<pair<int, int>> q;

void BFS(int x, int y)
{
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int tempX = q.front().first;
		int tempY = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			int newX = tempX + dx[a];
			int newY = tempY + dy[a];

			if (newX >= 0 && newX < N && newY >= 0 && newY < M)
			{
				if (visited[newX][newY] == 0 && farm[newX][newY] == 1)
				{
					q.push({ newX,newY });
					visited[newX][newY] = 1;
				}
			}
		}
	}
}
int main()
{
	fastio();
	cin >> T;
	while (T--)
	{
		memset(farm, 0, sizeof(farm));
		memset(visited, 0, sizeof(visited));
		cin >> M >> N >> K;
		int cnt = 0;
		while (K--)
		{
			cin >> y >> x;
			farm[x][y] = 1;
		}

		

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (farm[i][j] == 1 && visited[i][j] == 0)
				{
					BFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}