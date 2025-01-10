#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(vector<vector<int>>& tomato, vector<vector<int>>& days, int max_X, int max_Y) {
    queue<pair<int, int>> q;
    
    // 초기 상태에서 익은 토마토를 큐에 넣습니다.
    for (int i = 0; i < max_X; i++) {
        for (int j = 0; j < max_Y; j++) {
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                days[i][j] = 0; // 익은 토마토가 있는 위치의 날짜는 0으로 설정
            }
        }
    }

    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int fX = tempX + dx[i];
            int fY = tempY + dy[i];

            if (fX >= 0 && fX < max_X && fY >= 0 && fY < max_Y) {
                if (tomato[fX][fY] == 0 && days[fX][fY] == -1) { // 익지 않은 토마토라면
                    tomato[fX][fY] = 1;
                    days[fX][fY] = days[tempX][tempY] + 1;
                    q.push(make_pair(fX, fY));
                }
            }
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> tomato(N, vector<int>(M));
    vector<vector<int>> days(N, vector<int>(M, -1)); // 날짜를 추적하는 배열, 초기값 -1

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
        }
    }

    bfs(tomato, days, N, M);

    int max_days = 0;
    bool all_ripe = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                all_ripe = false;
            }
            max_days = max(max_days, days[i][j]);
        }
    }

    if (all_ripe) {
        cout << max_days << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
