#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int N) {
    vector<int> distance(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start}); // {cost, position}

    while (!pq.empty()) {
        int currCost = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currCost > distance[currNode]) continue;

        for (const auto& edge : graph[currNode]) {
            int nextNode = edge.first;
            int weight = edge.second;
            int newCost = currCost + weight;

            if (newCost < distance[nextNode]) {
                distance[nextNode] = newCost;
                pq.push({newCost, nextNode});
            }
        }
    }

    return distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});  // 양방향 간선
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist_from_1 = dijkstra(graph, 1, N);
    vector<int> dist_from_v1 = dijkstra(graph, v1, N);
    vector<int> dist_from_v2 = dijkstra(graph, v2, N);

    long long path1 = static_cast<long long>(dist_from_1[v1]) + dist_from_v1[v2] + dist_from_v2[N];
    long long path2 = static_cast<long long>(dist_from_1[v2]) + dist_from_v2[v1] + dist_from_v1[N];

    long long answer = min(path1, path2);

    if (answer >= INF) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}
