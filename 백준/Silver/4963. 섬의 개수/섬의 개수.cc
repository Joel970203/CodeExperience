#include <iostream>
#include <vector>
#include <cstring> // memset을 사용하기 위한 헤더 파일 추가
using namespace std;

// 상, 하, 좌, 우, 대각선 방향을 탐색하기 위한 8가지 방향
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
bool visited[51][51]; // 방문 여부를 저장하는 배열
int w, h; // 지도의 너비와 높이
vector<vector<int>> map; // 지도를 저장하는 2차원 벡터

// DFS를 이용한 탐색
void dfs(int x, int y) {
    visited[x][y] = true;

    // 8방향으로 탐색
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 지도의 범위를 벗어나지 않고, 아직 방문하지 않았으며, 땅(1)인 경우
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && map[nx][ny] == 1) {
            dfs(nx, ny); // 연결된 모든 땅을 방문 처리
        }
    }
}

int main() {
    while (true) {
        cin >> w >> h;

        // 입력이 0 0이면 종료
        if (w == 0 && h == 0) break;

        // 지도 초기화
        map = vector<vector<int>>(h, vector<int>(w, 0));
        memset(visited, false, sizeof(visited)); // 방문 배열 초기화

        // 지도 입력
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        int island_count = 0; // 섬의 개수를 저장할 변수

        // 모든 좌표를 탐색
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // 땅(1)이고 아직 방문하지 않았다면 새로운 섬
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j); // 연결된 모든 땅을 방문 처리
                    island_count++; // 섬의 개수 증가
                }
            }
        }

        // 섬의 개수를 출력
        cout << island_count << endl;
    }

    return 0;
}