#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int dx[5] = { 0, 0, 0, -1, 1 }; // 동 서 북 남
int dy[5] = { 0, 1, -1, 0, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    vector<int> dice(6, 0);

    while (K--) {
        int dir;
        cin >> dir;

        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue; // 범위 체크

        x = nx; y = ny;
        int temp[6];
        for (int i = 0; i < 6; i++) temp[i] = dice[i];

        if (dir == 1) { // 동
            dice[0] = temp[4]; dice[1] = temp[5];
            dice[4] = temp[1]; dice[5] = temp[0];
        }
        else if (dir == 2) { // 서
            dice[0] = temp[5]; dice[1] = temp[4];
            dice[4] = temp[0]; dice[5] = temp[1];
        }
        else if (dir == 3) { // 북
            dice[0] = temp[2]; dice[1] = temp[3];
            dice[2] = temp[1]; dice[3] = temp[0];
        }
        else if (dir == 4) { // 남
            dice[0] = temp[3]; dice[1] = temp[2];
            dice[2] = temp[0]; dice[3] = temp[1];
        }

        if (board[x][y] == 0) {
            board[x][y] = dice[1]; // 바닥면 복사
        }
        else {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[0] << "\n"; // 윗면 출력
    }
}
