#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

bool visited[601][601] = { 0 };
char path[601][601] = { 'X' };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;
char k;
int N, M;
int startX, startY;

void bfs(int startX, int startY)
{
	queue<pair<int, int>> q;
	q.push({ startX,startY });
	visited[startY][startX] = 1;
	while (!q.empty())
	{
		int frontX = q.front().first;
		int frontY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tempX = frontX + dx[i];
			int tempY = frontY + dy[i];

			if (tempX >= 0 && tempX < M && tempY >= 0 && tempY < N)
			{
				if (visited[tempY][tempX] == 0 && path[tempY][tempX] != 'X')
				{
					if (path[tempY][tempX] == 'P')
					{
						cnt++;
					}
					q.push({ tempX,tempY });
					visited[tempY][tempX] = 1;
				}
			}
		}
	}
	
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> k;
			if (k == 'I')
			{
				startX = j;
				startY = i;
			}
			path[i][j] = k;
		}
	}

	bfs(startX, startY);

	if (cnt != 0)
	{
		cout << cnt << endl;
	}
	else
	{
		cout << "TT" << endl;
	}
}