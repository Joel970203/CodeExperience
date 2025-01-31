#include <iostream>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;


vector<int> n[100001];
vector<int> tree[100001];
int treeSize[100001];

void createTree(int parent, int now) {
    for (int next : n[now]) {
        if (next == parent) continue;
        tree[now].push_back(next);
        createTree(now, next);
    }
}

void findSize(int node) {
    treeSize[node] = 1;

    for (int next : tree[node]) {
        findSize(next);
        treeSize[node] += treeSize[next];
    }
}

int main() {
    fastio();
    int N, R, Q;
    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        n[U].push_back(V);
        n[V].push_back(U);
    }

    createTree(0, R);
    findSize(R);

    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        cout << treeSize[a] << "\n";
    }

    return 0;
}
