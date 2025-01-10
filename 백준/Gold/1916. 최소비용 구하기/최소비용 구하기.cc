#include <iostream>
#include <queue>
#include <vector>
#include <limits>

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대 값 정의

// 다익스트라 알고리즘 구현 함수
vector<int> dijkstra(int N, vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(N + 1, INF); // 최단 거리 배열 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙
    
    dist[start] = 0;
    pq.push({0, start}); // 출발 정점에 대한 초기화

    while (!pq.empty()) {
        int d = pq.top().first; // 현재까지의 거리
        int u = pq.top().second; // 현재 정점
        pq.pop();

        if (d > dist[u]) continue; // 이미 최단 거리인 경우

        // 인접 정점 확인
        for (const auto& edge : graph[u]) {
            int v = edge.first; // 인접 정점
            int weight = edge.second; // 간선 가중치
            int newDist = d + weight; // 새로운 거리 계산

            if (newDist < dist[v]) { // 새로운 거리가 더 짧은 경우
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    return dist;
}

int main() {
    fastio();
    int N, M;
    cin >> N >> M; // 정점 수와 간선 수 입력

    vector<vector<pair<int, int>>> graph(N + 1); // 그래프 초기화

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end; // 시작 정점과 끝 정점 입력

    vector<int> distance = dijkstra(N, graph, start); // 다익스트라 알고리즘 실행

    // 결과 출력
    if (distance[end] == INF) {
        cout << "INF" << endl;
    } else {
        cout << distance[end] << endl;
    }

    return 0;
}
