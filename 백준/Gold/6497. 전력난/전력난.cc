#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

int prim(const vector<vector<pair<int, int>>>& graph, int m) {
    vector<bool> visited(m, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); // {weight, node}
    int mstweight = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        mstweight += weight;

        for (const auto& [e_node, e_weight] : graph[node]) {
            if (!visited[e_node]) {
                pq.push({e_weight, e_node});
            }
        }
    }
    return mstweight;
}

int main() {
    while (true) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int m, n;
        ss >> m >> n;

        if (m == 0 && n == 0) break;

        vector<vector<pair<int, int>>> graph(m);
        int total = 0;

        for (int i = 0; i < n; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            total += weight;
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }

        // Consume the newline character left by `cin`
        cin.ignore();

        int result = total - prim(graph, m);
        cout << result << endl;
    }

    return 0;
}
