#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> graph(300, vector<int>(300)); // 빙산 배열
bool visited[300][300]; // 방문 여부 체크
int N, M; // 세로 크기 N, 가로 크기 M
int dx[4] = { 1, -1, 0, 0 }; // 상하좌우 이동
int dy[4] = { 0, 0, 1, -1 };

// 빙산 덩어리 체크를 위한 DFS 함수
void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && graph[nx][ny] > 0) {
            dfs(nx, ny);
        }
    }
}

// 빙산을 녹이는 함수
void melt() {
    vector<vector<int>> temp = graph; // 빙산을 녹일 임시 배열

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] > 0) { // 빙산이 있는 곳만 녹인다.
                int seaCnt = 0; // 인접한 바다의 수
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M && graph[ni][nj] == 0) {
                        seaCnt++;
                    }
                }
                temp[i][j] = max(0, graph[i][j] - seaCnt); // 빙산이 0 이하로 줄어들지 않도록 처리
            }
        }
    }

    graph = temp; // 녹인 후 배열 업데이트
}

int countIcebergs() {
    int count = 0; // 빙산 덩어리 수
    memset(visited, false, sizeof(visited)); // 방문 배열 초기화

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] > 0 && !visited[i][j]) { // 방문하지 않은 빙산 덩어리 발견
                dfs(i, j); // 해당 덩어리 DFS로 방문 처리
                count++;
            }
        }
    }

    return count;
}

int main() {
    cin >> N >> M;

    // 빙산 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int year = 0;
    while (true) {
        int icebergCount = countIcebergs(); // 빙산 덩어리 개수 세기

        if (icebergCount >= 2) { // 두 덩어리 이상이면 종료
            cout << year << endl;
            break;
        }

        if (icebergCount == 0) { // 빙산이 모두 녹았으면 0 출력
            cout << 0 << endl;
            break;
        }

        melt(); // 빙산 녹이기
        year++; // 시간 증가
    }

    return 0;
}
