#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long prim(int N, const vector<vector<pair<int, int>>>& graph) {
    vector<bool> visited(N + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    pq.emplace(0, 1); // 가중치, 노드
    long long mstWeight = 0;
    int visitedCount = 0;

    while (!pq.empty()) {
        long long weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        mstWeight += weight;
        visitedCount++;

        for (const auto& neighbor : graph[node]) {
            long long w = neighbor.first;
            int v = neighbor.second;

            if (!visited[v]) {
                pq.emplace(w, v);
            }
        }
    }

    if (visitedCount != N) return -1;

    return mstWeight;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    long long totalCost = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        long long weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(weight, v);
        graph[v].emplace_back(weight, u);
        totalCost += weight;
    }

    long long mstCost = prim(N, graph);

    if (mstCost == -1) {
        cout << -1 << endl;
    }
    else {
        cout << totalCost - mstCost << endl;
    }

    return 0;
}
