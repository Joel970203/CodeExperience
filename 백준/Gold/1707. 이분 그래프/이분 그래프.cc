#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// DFS로 이분 그래프인지 확인하는 함수
bool isBipartite(const vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
    colors[node] = color; // 현재 노드에 색칠

    for (int neighbor : graph[node]) 
    {
        // 인접한 정점이 같은 색이면 이분 그래프가 아님
        if (colors[neighbor] == color)
            return false;

        // 인접한 정점이 아직 방문되지 않았다면 반대 색으로 칠하며 재귀 호출
        if (colors[neighbor] == 0 && !isBipartite(graph, colors, neighbor, -color))
            return false;
    }
    return true;
}

int main() {
    fastio();
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) 
    {
        int v, e;
        cin >> v >> e;

        // 그래프 입력
        vector<vector<int>> graph(v + 1); // 1부터 시작하는 정점 번호
        for (int j = 0; j < e; j++) 
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); // 무향 그래프
        }

        // 색깔 정보를 저장 (0: 미방문, 1: 빨강, -1: 파랑)
        vector<int> colors(v + 1, 0);
        bool is_bipartite = true;

        // 모든 정점에 대해 DFS 실행 (비연결 그래프를 고려)
        for (int node = 1; node <= v; node++) 
        {
            if (colors[node] == 0) { // 아직 방문하지 않은 정점만 탐색
                if (!isBipartite(graph, colors, node, 1)) 
                {
                    is_bipartite = false;
                    break;
                }
            }
        }

        // 결과 출력
        if (is_bipartite)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
