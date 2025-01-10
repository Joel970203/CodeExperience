#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dijkstra(int N, int D, vector<vector<pair<int, int>>>& graph)
{
	vector<int> dist(D + 1, INT_MAX);
	dist[0] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });  // (현재까지 거리, 현재 위치)

	while (!pq.empty())
	{
		int currDist = pq.top().first;
		int currPos = pq.top().second;
		pq.pop();

		if (currDist < dist[currPos]) // 처리 된 경우
		{
			continue;
		}

		if (currPos + 1 <= D && dist[currPos + 1] > currDist + 1)
		{
			dist[currPos + 1] = currDist + 1;
			pq.push({ dist[currPos + 1],currPos + 1 });
		}

		for (auto& shortcut : graph[currPos]) {
			int nextPos = shortcut.first;
			int shortcutDist = shortcut.second;

			if (nextPos <= D && dist[nextPos] > currDist + shortcutDist) {
				dist[nextPos] = currDist + shortcutDist;
				pq.push({ dist[nextPos], nextPos });
			}
		}
	}
	return dist[D];
}

int main() {
	int N, D;
	cin >> N >> D;
	vector<vector<pair<int, int>>> graph(D + 1);

	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (b <= D) {  // 지름길이 고속도로 길이를 초과하지 않는 경우만 추가
			graph[a].push_back({ b, c });
		}
	}

	cout << dijkstra(N, D, graph) << endl;

	return 0;
}