#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int u, v, weight;
	Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compare(const Edge& a, const Edge& b)
{
	return a.weight < b.weight;
}

class UnionFind
{
public:
	vector<int> depth, root;

	UnionFind(int n)
	{
		depth.resize(n + 1, 0);
		root.resize(n + 1);
		for (int i = 0; i <= n; i++)  
		{
			root[i] = i;
		}
	}

	int Find(int x)
	{
		if (root[x] == x)
		{
			return x;
		}
		else
		{
			return root[x] = Find(root[x]);
		}
	}

	void Union(int x, int y)  
	{
		int R_x = Find(x);
		int R_y = Find(y);

		if (R_x == R_y)  
		{
			return;
		}

		if (depth[R_x] < depth[R_y])  
		{
			root[R_x] = R_y;
		}
		else if (depth[R_x] > depth[R_y])  
		{
			root[R_y] = R_x;
		}
		else  
		{
			root[R_y] = R_x;
			depth[R_x]++;
		}
	}
};

int main()
{
	int V, E;
	cin >> V >> E;
	vector<Edge> Edges;
	for (int i = 0; i < E; i++)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		Edges.emplace_back(u, v, weight);
	}

	sort(Edges.begin(), Edges.end(), compare);

	UnionFind uf(V);
	long long mstWeight = 0;
	int cnt = 0;

	for (const auto& edge : Edges)
	{
		if (uf.Find(edge.u) != uf.Find(edge.v))
		{
			uf.Union(edge.u, edge.v);
			mstWeight += edge.weight;
			cnt++;
			if (cnt == V - 1) break;  
		}
	}

	cout << mstWeight << endl;
	return 0;
}
