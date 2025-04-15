#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
using namespace std;

int K, N, F;
vector<vector<int>> graph;
vector<int> arr;

void dfs(int start) 
{
	if (arr.size() == K)
	{
		for (int x : arr) cout << x << "\n";
		exit(0); 
	}

	for (int i = start; i <= N; i++) 
	{
		bool ok = true;
		for (int x : arr) 
		{
			if (graph[i][x] == 0) 
			{ 
				ok = false;
				break;
			}
		}

		if (ok) 
		{
			arr.push_back(i);
			dfs(i + 1);
			arr.pop_back();
		}
	}
}

int main() {
	
	fastio();
	cin >> K >> N >> F;
	graph.assign(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < F; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	dfs(1); 

	cout << -1 << "\n"; 
}
