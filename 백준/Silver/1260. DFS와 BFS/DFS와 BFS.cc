#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visited_dfs(1001, false);
vector<bool> visited_bfs(1001, false);

void dfs(const vector<vector<int>>& graph, int start)
{
	visited_dfs[start] = true;
	cout << start << " ";
	for (const auto& dir : graph[start])
	{
		if (visited_dfs[dir] == false)
		{
			dfs(graph, dir);
		}
	}
	return;
}


void bfs(const vector<vector<int>>& graph, int start)
{
	queue<int> q;
	q.push(start);
	visited_bfs[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		cout << cur << " ";
		q.pop();

		for (const auto& dir : graph[cur])
		{
			if (visited_bfs[dir] == false)
			{
				visited_bfs[dir] = true;
				q.push(dir);
			}
		}
	}

	cout << endl;
	return;
}

int main()
{
	int N, M, V, K;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1); 

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u); 
	}

	for (int i = 0; i < graph.size(); i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(graph, V);
	cout << endl;
	bfs(graph, V);

}