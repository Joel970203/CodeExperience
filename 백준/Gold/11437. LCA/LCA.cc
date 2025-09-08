#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<vector<int>> tree;
vector<int> visited;
vector<int> parent;
vector<int> depth;

void bfs(int root)
{
    queue<int> q;
    visited[root] = true;
    depth[root] = 0;
    parent[root] = 0;
    q.push(root); 

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int nxt : tree[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                parent[nxt] = cur; 
                depth[nxt] = depth[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int lca(int a, int b)
{
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main()
{
    cin >> N;

    tree.resize(N + 1);
    visited.resize(N + 1);
    parent.resize(N + 1);
    depth.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bfs(1);

    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}
