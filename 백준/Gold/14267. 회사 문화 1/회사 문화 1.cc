#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> praise;


void dfs(int start)
{
	for (int next : adj[start])
	{
		praise[next] += praise[start];
		dfs(next);
	}
}

int main()
{
	cin >> n >> m;
	adj.resize(n + 1);
	praise.resize(n + 1,0);

	for (int i = 1; i <= n; ++i)
	{
		int boss;
		cin >> boss;
		if (boss != -1)
		{
			adj[boss].push_back(i);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int parent, weight;
		cin >> parent >> weight;
		praise[parent] += weight;
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << praise[i] << (i == n ? "" : " ");
	}

	return 0;
}