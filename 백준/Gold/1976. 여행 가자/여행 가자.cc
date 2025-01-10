#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

// Find 연산: 경로 압축을 적용하여 효율적으로 부모를 찾음
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 경로 압축
    }
    return parent[x];
}

// Union 연산: 두 집합을 합침
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX; // 루트 Y를 루트 X에 합침
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 초기화
    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    // 연결 정보 입력 및 Union 연산
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int connected;
            cin >> connected;
            if (connected == 1) {
                unionSets(i, j);
            }
        }
    }

    // 여행 계획 입력
    vector<int> plan(M);
    for (int i = 0; i < M; ++i) {
        cin >> plan[i];
    }

    // 여행 계획의 모든 도시가 같은 집합에 있는지 확인
    int root = find(plan[0]); // 여행 계획의 첫 도시의 루트
    bool possible = true;
    for (int i = 1; i < M; ++i) {
        if (find(plan[i]) != root) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
