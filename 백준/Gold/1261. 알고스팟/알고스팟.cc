#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M, N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int d[100][100];
string board[100];
int answer = 1e9;
queue<pair<int, int>> q;


void solve(int x, int y) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = 1e9;
        }
    }

    d[x][y] = 0;

    q.push({ x,y });

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (board[nx][ny] == '0') {
                if (d[nx][ny] > d[cur.first][cur.second]) {
                    d[nx][ny] = d[cur.first][cur.second];
                    q.push({ nx,ny });
                }
            }
            else {
                if (d[nx][ny] > d[cur.first][cur.second] + 1) {
                    d[nx][ny] = d[cur.first][cur.second] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}
int main() {

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    solve(0, 0);


    cout << d[N - 1][M - 1];
    return 0;
}