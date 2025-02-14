#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;
vector<string> graph;
bool visited[100][100] = { false };


bool bfs(int x, int y, char color)
{
    if (visited[y][x]) return false; // 이미 방문한 곳이면 false

    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[y][x] = true;

    while (!q.empty())
    {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int curX = tempX + dx[i];
            int curY = tempY + dy[i];

            if (curX >= 0 && curX < N && curY >= 0 && curY < N)
            {
                if (!visited[curY][curX] && graph[curY][curX] == color)
                {
                    q.push({ curX,curY });
                    visited[curY][curX] = true;
                }
            }
        }
    }
    return true; // 새로운 영역이므로 true 반환
}

int main()
{
	cin >> N;
	graph.resize(N);
	int cnt = 0;
    int cnt2 = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> graph[i];
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				cnt += bfs(j, i, graph[i][j]);
			}

		}
	}


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 'R')
            {
                graph[i][j] = 'G';
            }
        }
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                cnt2 += bfs(j, i, graph[i][j]);
            }

        }
    }
    cout << cnt << " " << cnt2 << endl;
}