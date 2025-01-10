#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> adj[10001];  // 인접 리스트
int N, M;

int bfs(int start) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;  // 시작 노드도 해킹 가능

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    return count;
}

int main() {
    fastio();
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);  // b를 해킹하면 a도 해킹 가능
    }

    vector<int> result;
    int max_hack = 0;

    for (int i = 1; i <= N; i++) {
        int hacked = bfs(i);
        if (hacked > max_hack) {
            max_hack = hacked;
            result.clear();
            result.push_back(i);
        }
        else if (hacked == max_hack) {
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());
    for (int comp : result) {
        cout << comp << " ";
    }

    return 0;
}
