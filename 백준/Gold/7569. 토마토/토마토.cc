#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y, z;
};

int M, N, H;
int graph[100][100][100] = { -1 };  // 토마토 저장소
bool visited[100][100][100] = { 0 }; // 방문 여부 체크

int dx[6] = { 1, -1, 0, 0, 0, 0 };  // 동서남북위아래 
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

// BFS 함수
int bfs() {
    queue<Point> q;

    // 초기 익은 토마토의 위치를 큐에 추가
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (graph[h][n][m] == 1) {
                    q.push({ m, n, h });
                    visited[h][n][m] = true; // 방문 체크
                }
            }
        }
    }

    int days = -1; // 날 수 카운트

    // BFS 탐색
    while (!q.empty()) {
        int size = q.size(); // 현재 레벨의 크기

        for (int i = 0; i < size; i++) {
            int tempX = q.front().x;
            int tempY = q.front().y;
            int tempZ = q.front().z;
            q.pop();

            for (int j = 0; j < 6; j++) {
                int curX = tempX + dx[j];
                int curY = tempY + dy[j];
                int curZ = tempZ + dz[j];

                if (curX >= 0 && curX < M && curY >= 0 && curY < N && curZ >= 0 && curZ < H) {
                    if (graph[curZ][curY][curX] == 0 && !visited[curZ][curY][curX]) {
                        visited[curZ][curY][curX] = true; // 방문 체크
                        graph[curZ][curY][curX] = 1; // 익은 토마토로 상태 변경
                        q.push({ curX, curY, curZ }); // 큐에 추가
                    }
                }
            }
        }
        days++; // 하루가 지나감
    }

    // 모든 토마토가 익었는지 확인
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (graph[h][n][m] == 0) {
                    return -1; // 익지 않은 토마토가 존재하면 -1 반환
                }
            }
        }
    }

    return days; // 최소 일수 반환
}

int main() {
    cin >> M >> N >> H;

    // 3차원 배열의 각 층을 입력받기
    for (int h = 0; h < H; h++) { // 각 상자(층)
        for (int n = 0; n < N; n++) { // 각 세로 칸
            for (int m = 0; m < M; m++) { // 각 가로 칸
                cin >> graph[h][n][m]; // 3차원 배열에 입력
            }
        }
    }

    int ans = bfs(); // BFS 함수 호출
    cout << ans << endl; // 결과 출력

    return 0;
}
