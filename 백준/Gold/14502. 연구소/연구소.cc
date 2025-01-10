#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::next_permutation
#include <climits> // for INT_MIN

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// BFS를 통해 바이러스 확산 후 남아있는 안전 영역 계산
int bfs(vector<vector<int>>& lab, int max_X, int max_Y) {
    vector<vector<int>> lab2(lab);
    int cnt = 0;
    queue<pair<int, int>> q;

    // 모든 바이러스의 위치를 큐에 추가
    for (int i = 0; i < max_X; i++) {
        for (int j = 0; j < max_Y; j++) {
            if (lab2[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    // BFS
    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int fX = tempX + dx[i];
            int fY = tempY + dy[i];

            if (fX >= 0 && fX < max_X && fY >= 0 && fY < max_Y) {
                if (lab2[fX][fY] == 0) {
                    q.push(make_pair(fX, fY));
                    lab2[fX][fY] = 2;
                }
            }
        }
    }

    // 남아있는 안전 영역의 개수 계산
    for (int k = 0; k < max_X; k++) {
        for (int l = 0; l < max_Y; l++) {
            if (lab2[k][l] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

// 벽을 세우고 최대 안전 영역을 찾는 함수
int findMaxSafeArea(vector<vector<int>>& lab, int N, int M) {
    vector<pair<int, int>> emptySpaces;
    
    // 빈 공간의 위치를 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 0) {
                emptySpaces.push_back(make_pair(i, j));
            }
        }
    }
    
    int maxSafeArea = 0;

    // 3개의 빈 공간을 벽으로 선택하는 조합 생성
    for (int i = 0; i < emptySpaces.size(); i++) {
        for (int j = i + 1; j < emptySpaces.size(); j++) {
            for (int k = j + 1; k < emptySpaces.size(); k++) {
                vector<vector<int>> labCopy = lab;
                labCopy[emptySpaces[i].first][emptySpaces[i].second] = 1;
                labCopy[emptySpaces[j].first][emptySpaces[j].second] = 1;
                labCopy[emptySpaces[k].first][emptySpaces[k].second] = 1;

                int safeArea = bfs(labCopy, N, M);
                maxSafeArea = max(maxSafeArea, safeArea);
            }
        }
    }

    return maxSafeArea;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> lab(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
        }
    }

    cout << findMaxSafeArea(lab, N, M) << endl;

    return 0;
}
