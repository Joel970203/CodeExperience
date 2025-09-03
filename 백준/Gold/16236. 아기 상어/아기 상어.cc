#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 }; // 왼쪽 우선, 위쪽은 다음 

int N, M, cnt = 0, sharkSize = 2, fishCnt = 0;
int sharkY, sharkX;

struct Fish
{
	int y, x, dist;
};

Fish bfs(int y, int x, vector<vector<int>> &graph)
{
	bool foundFish = false;
	bool visited[20][20] = {false};
	queue<Fish> q;
	q.push({ y,x,0});
	visited[y][x] = true;
	
	vector<Fish> candidates;
	int minDist = -1;

	while (!q.empty())
	{
		auto [y, x, dist] = q.front();
		q.pop();

		if (minDist != -1 && dist > minDist) break;

		if (graph[y][x] != 0 && graph[y][x] < sharkSize) {
			candidates.push_back({ y,x,dist });
			minDist = dist; 
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if (visited[ny][nx]) continue;
			if (graph[ny][nx] > sharkSize) continue;
			visited[ny][nx] = true;
			q.push({ ny,nx,dist + 1 });
		}
	}

	if(candidates.empty()) return { -1, -1, -1 };

	sort(candidates.begin(), candidates.end(), [](Fish a, Fish b) {
		if (a.dist != b.dist) return a.dist < b.dist;
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	});

	auto target = candidates[0];
	graph[target.y][target.x] = 0; // 먹은 칸은 빈칸 처리
	return target;
}

int main()
{
	cin >> N;
	
	vector<vector<int>> graph(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				sharkY = i; sharkX = j;
				graph[i][j] = 0; // 상어 위치는 빈칸으로 초기화
			}
		}
	}

	int answer = 0, ate = 0;
	while (true) {
		auto [y, x, dist] = bfs(sharkY, sharkX, graph);
		if (y == -1) break;

		sharkY = y; sharkX = x;
		answer += dist;
		ate++;

		if (ate == sharkSize) {
			sharkSize++;
			ate = 0;
		}
	}
	cout << answer << "\n";
}