#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[100][100] = { false };

int bfs(const vector<vector<int>>& graph,int N,int M)
{
	queue<pair<int, pair<int, int>>> q;
	visited[0][0] = true;
	q.push({ 1, { 0,0 } });
	while (!q.empty())
	{
		auto [dist, pos] = q.front();
		auto [curY, curX] = pos;
		q.pop();

		if (curY == N - 1 && curX == M - 1)
		{
			return dist;
		}

		for (int i = 0; i < 4; i++)
		{
			auto dirY = curY + dy[i];
			auto dirX = curX + dx[i];

			if (dirY >= 0 && dirY < N && dirX >= 0 && dirX < M && graph[dirY][dirX] == 1)
			{
				if (visited[dirY][dirX] == false)
				{
					visited[dirY][dirX] = true;
					q.push({ dist+1,{dirY,dirX} });
				}
			}

		}
	}

	return -1;

}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N,vector<int>(M));
	
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			graph[i][j] = line[j] - '0';  
		}
	}


	int answer = bfs(graph,N,M);

	cout << answer;
}