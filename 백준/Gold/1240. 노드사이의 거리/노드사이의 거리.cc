#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<vector<pair<int, int>>> graph;

int dfs(int current, int target, vector<bool>& visited) {
    if (current == target) return 0;  

    visited[current] = true;
    for (auto& neighbor : graph[current]) {
        int next = neighbor.first;
        int dist = neighbor.second;

        if (!visited[next]) {
            int path = dfs(next, target, visited);
            if (path != -1) {
                return dist + path;  
            }
        }
    }
    return -1;  // 목표를 찾을 수 없으면 -1 반환
}

int main() {
    fastio();
    int N, M;
    cin >> N >> M;

    graph.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;  
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  

        vector<bool> visited(N, false);
        int result = dfs(u, v, visited);
        cout << result << endl;
    }

    return 0;
}
