#include <iostream>
#include <vector>

using namespace std;

vector<int> root;
vector<int> depth;
vector<bool> visited;

// Find 함수: 루트 노드를 찾으면서 경로 압축
int Find(int x) {
    if (root[x] == x) {
        return x;
    }
    return root[x] = Find(root[x]);
}

// Union 함수: 두 집합을 병합
void Union(int x, int y) {
    int pX = Find(x);
    int pY = Find(y);

    if (pX == pY) return;

    if (depth[pX] < depth[pY]) {
        root[pX] = pY;
    }
    else {
        root[pY] = pX;
        if (depth[pX] == depth[pY]) {
            depth[pX]++;
        }
    }
}

int main() {
    int N, M; // 사람의 수 N, 파티의 수 M
    cin >> N >> M;

    // 초기화
    root.resize(N + 1);
    depth.resize(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        root[i] = i; 
    }

    int know;
    cin >> know;
    vector<int> knowing(know);
    for (int i = 0; i < know; i++) {
        cin >> knowing[i];
    }

    for (int i = 1; i < know; i++) {
        Union(knowing[0], knowing[i]);
    }

    vector<vector<int>> parties(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        parties[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> parties[i][j];
        }
        for (int j = 1; j < k; j++) {
            Union(parties[i][0], parties[i][j]);
        }
    }

    int truthRoot = -1;
    if (!knowing.empty()) {
        truthRoot = Find(knowing[0]);
    }

    int answer = 0;
    for (const auto& party : parties) {
        bool canLie = true;
        for (int person : party) {
            if (Find(person) == truthRoot) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
