#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)


using namespace std;

int parent[10001];

struct Edge
{
	int u, v, w;
	bool operator<(const Edge& other) const
	{
		return w < other.w;
	}
};


int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA != rootB)
	{
		parent[rootA] = b;
	}
}

int main()
{
	fastio();
	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; ++i)
	{
		parent[i] = i;
	}

	vector<Edge> edges;

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u,v,w });
	}

	sort(edges.begin(), edges.end());

	long long result = 0;
	int edgeCount = 0;

	for (int i = 0; i < E; i++)
	{
		if (edgeCount == V - 1) break;

		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;

		if (Find(u) != Find(v))
		{
			Union(u, v);
			result += w;
			edgeCount++;
		}
	}

	cout << result << endl;

	return 0;
}