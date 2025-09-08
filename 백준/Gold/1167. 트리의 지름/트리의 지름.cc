#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int V, farNode, maxDist;
vector<pair<int, int>> tree[100001];
bool visited[100001];

void dfs(int cur, int dist) {
    visited[cur] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farNode = cur;
    }
    for (auto& edge : tree[cur]) {
        int nxt = edge.first, w = edge.second;
        if (!visited[nxt]) {
            dfs(nxt, dist + w);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V;
    for (int i = 1; i <= V; i++) {
        int u;
        cin >> u;
        while (true) {
            int v; cin >> v;
            if (v == -1) break;
            int w; cin >> w;
            tree[u].push_back({ v,w });
        }
    }

    // 1st DFS
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    // 2nd DFS from farNode
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farNode, 0);

    cout << maxDist<< "\n";
    return 0;
}
