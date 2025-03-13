#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State
{
	int rx, ry, bx, by, depth;
};

vector<vector<char>> graph;
pair<int, int> red, blue, goal;
vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool visited[10][10][10][10];


void move(int& x, int& y, int dx, int dy, int& count)
{
	while (graph[x + dx][y + dy] != '#' && graph[x][y] != 'O')
	{
		x += dx;
		y += dy;
		count++;
	}
}
int bfs()
{
	queue<State> q;
	q.push({ red.first, red.second, blue.first, blue.second, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int rx = cur.rx, ry = cur.ry, bx = cur.bx, by = cur.by, depth = cur.depth;

		if (depth >= 10)
		{
			return -1;
		}

		for (auto dir : directions)
		{
			int dx = dir.first;
			int dy = dir.second;

			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int r_moves = 0, b_moves = 0;

			move(nrx, nry, dx, dy, r_moves);
			move(nbx, nby, dx, dy, b_moves);

			if (graph[nbx][nby] == 'O') continue;  
			if (graph[nrx][nry] == 'O') return depth + 1;  


			if (nrx == nbx && nry == nby)
			{
				if (r_moves > b_moves)
				{
					nrx -= dx;
					nry -= dy;
				}
				else
				{
					nbx -= dx;
					nby -= dy;
				}
			}

			if (!visited[nrx][nry][nbx][nby])
			{
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx, nry, nbx, nby, depth + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	int N, M;
	cin >> N >> M;

	graph.resize(N, vector<char>(M));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;

			if (c == 'R')
			{
				red.first = i;
				red.second = j;
			}

			if (c == 'B')
			{
				blue.first = i;
				blue.second = j;
			}

			if (c == 'O')
			{
				goal.first = i;
				goal.second = j;
			}

			graph[i][j] = c;
		}
	}

	cout << bfs() << endl;
}