#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool tryCross(const vector<vector<pair<int, int>>>& graph, int s, int e, int limit) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true; 

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        if (temp == e) {
            return true; 
        }

        for (const auto& edge : graph[temp]) {
            int next = edge.first;
            int weight = edge.second;

            if (!visited[next] && weight >= limit) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false; 
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    int u, v, weight;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }

    int s, e;
    cin >> s >> e;

    int low = 1, high = 1e9;
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (tryCross(graph, s, e, mid)) {
            ans = mid; 
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }

    cout << ans << endl;
    return 0;
}
