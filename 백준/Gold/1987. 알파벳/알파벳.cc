#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<string> board;
int dx[4] = { 1, -1, 0, 0 }; // 상하좌우 이동을 위한 배열
int dy[4] = { 0, 0, 1, -1 };

int max_count = 0;

// DFS 함수
void dfs(int x, int y, int count, int visited) {
    max_count = max(max_count, count);

    // 상하좌우로 이동
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 보드 범위를 벗어나지 않는지 확인
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            int next_alpha = board[nx][ny] - 'A'; // 해당 칸의 알파벳 인덱스

            // 해당 알파벳을 방문한 적이 없으면
            if (!(visited & (1 << next_alpha))) {
                dfs(nx, ny, count + 1, visited | (1 << next_alpha)); // 해당 알파벳 방문 처리
            }
        }
    }
}

int main() {
    cin >> R >> C;
    board.resize(R);

    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    // 좌측 상단에서 시작
    dfs(0, 0, 1, 1 << (board[0][0] - 'A'));

    // 결과 출력
    cout << max_count << endl;

    return 0;
}
