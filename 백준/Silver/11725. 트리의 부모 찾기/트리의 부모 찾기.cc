#include <iostream>
#include <vector>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> adj[100001];
int parent[100001]; // 부모 노드를 저장할 배열

void dfs(int node, int par) {
    parent[node] = par; // 현재 노드의 부모를 저장
    for (int next : adj[node]) {
        if (next != par) { // 부모 노드를 다시 방문하지 않기 위해
            dfs(next, node);
        }
    }
}

int main() {
    fastio();
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 1번 노드를 루트로 DFS 시작
    dfs(1, 0);

    // 2번 노드부터 N번 노드까지 부모 노드 출력
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}