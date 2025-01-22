#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class UnionFind {
public:
    vector<int> root, rank;

    UnionFind(int N) {
        root.resize(N + 1);
        rank.resize(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            root[i] = i;
        }
    }

    int Find(int x) {
        if (x == root[x]) return x;
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            }
            else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    fastio();
    int N;
    cin >> N;

    vector<Edge> edges;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cost;
            cin >> cost;
            if (i < j) 
            { 
                edges.emplace_back(i + 1, j + 1, cost);
            }
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf(N);
    long long mstWeight = 0;
    
    for (const auto& edge : edges) {
        if (uf.Find(edge.u) != uf.Find(edge.v)) {
            uf.Union(edge.u, edge.v);
            mstWeight += edge.weight;
        }
    }

    cout << mstWeight << endl;

    return 0;
}
