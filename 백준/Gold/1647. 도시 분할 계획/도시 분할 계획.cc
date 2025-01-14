#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class UnionFind
{
public:
    vector<int> depth, root;

    UnionFind(int N)
    {
        depth.resize(N + 1, 0);
        root.resize(N + 1);
        for (int i = 1; i <= N; i++)
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
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y)
    {
        int curX = Find(x);
        int curY = Find(y);

        if (curX == curY)
        {
            return;
        }

        if (depth[curX] < depth[curY])
        {
            root[curX] = curY;
        }
        else if (depth[curX] > depth[curY])
        {
            root[curY] = curX;
        }
        else
        {
            root[curY] = curX;
            depth[curX]++;
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;

    for (int i = 0; i < M; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.emplace_back(u, v, weight);
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf(N);
    long long mstweight = 0;
    int maxEdgeWeight = 0;

    for (const auto& edge : edges)
    {
        if (uf.Find(edge.u) != uf.Find(edge.v))
        {
            uf.Union(edge.u, edge.v);
            mstweight += edge.weight;
            maxEdgeWeight = max(maxEdgeWeight, edge.weight);
        }
    }

    cout << mstweight - maxEdgeWeight << endl;

    return 0;
}
