#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K, L;
int dx[4] = { 1, 0, -1, 0 }; // 오른쪽, 아래, 왼쪽, 위
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    vector<vector<int>> graph(N, vector<int>(N, 0)); // 0=빈칸, 1=사과

    // 사과 위치
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1; // 입력은 1-based, 저장은 0-based
    }

    cin >> L;
    vector<pair<int, char>> turns(L);
    for (int i = 0; i < L; i++) {
        cin >> turns[i].first >> turns[i].second;
    }

    deque<pair<int, int>> snake;
    snake.push_back({ 0,0 }); // 뱀 초기 위치
    vector<vector<int>> snakeBody(N, vector<int>(N, 0));
    snakeBody[0][0] = 1;

    int dir = 0; // 처음 방향: 오른쪽
    int time = 0;
    int turnIdx = 0;

    while (true) {
        time++;

        // 머리 좌표
        int headY = snake.front().first;
        int headX = snake.front().second;
        int ny = headY + dy[dir];
        int nx = headX + dx[dir];

        // 벽 충돌
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;
        // 자기 몸과 충돌
        if (snakeBody[ny][nx] == 1) break;

        // 머리 이동
        snake.push_front({ ny,nx });
        snakeBody[ny][nx] = 1;

        if (graph[ny][nx] == 1) {
            graph[ny][nx] = 0; // 사과 먹었으면 꼬리 안 줄임
        }
        else {
            // 꼬리 제거
            auto tail = snake.back();
            snake.pop_back();
            snakeBody[tail.first][tail.second] = 0;
        }

        // 방향 전환
        if (turnIdx < L && turns[turnIdx].first == time) {
            if (turns[turnIdx].second == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
            turnIdx++;
        }
    }

    cout << time << "\n";
    return 0;
}
