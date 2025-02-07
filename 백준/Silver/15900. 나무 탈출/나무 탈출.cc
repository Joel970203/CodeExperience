#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 500001;
vector<int> tree[MAX_N];
bool visited[MAX_N];

int main() {
    int N;
    cin >> N;

    // 트리 구성
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int depth_sum = 0;
    queue<pair<int, int>> q; // (노드, 깊이)
    memset(visited, false, sizeof(visited));

    // BFS 초기화
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();

        bool is_leaf = true;

        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
                is_leaf = false;
            }
        }

        // 리프 노드인 경우 깊이를 depth_sum에 추가
        if (is_leaf) {
            depth_sum += depth;
        }
    }

    // 깊이 합이 홀수면 성원이가 승리, 짝수면 형석이가 승리
    cout << (depth_sum % 2 == 1 ? "Yes" : "No") << endl;

    return 0;
}
