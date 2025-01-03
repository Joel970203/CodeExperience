#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int S;
bool visited[1001][1001]; // visited[화면 이모티콘 수][클립보드 이모티콘 수]

int bfs(int s) {
    queue<pair<int, int>> q; // {화면 이모티콘 수, 클립보드 이모티콘 수}
    q.push({ 1, 0 }); // 처음 시작: 화면에 1개의 이모티콘, 클립보드는 비어있음
    visited[1][0] = true;

    int time = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            int screen = q.front().first;
            int clipboard = q.front().second;
            q.pop();

            if (screen == S) { // 목표 달성
                return time;
            }

            // 1. 화면에 있는 이모티콘을 복사해서 클립보드에 저장
            if (!visited[screen][screen]) {
                visited[screen][screen] = true;
                q.push({ screen, screen });
            }

            // 2. 클립보드의 이모티콘을 화면에 붙여넣기
            if (clipboard > 0 && screen + clipboard <= 1000 && !visited[screen + clipboard][clipboard]) {
                visited[screen + clipboard][clipboard] = true;
                q.push({ screen + clipboard, clipboard });
            }

            // 3. 화면의 이모티콘 하나 삭제
            if (screen > 1 && !visited[screen - 1][clipboard]) {
                visited[screen - 1][clipboard] = true;
                q.push({ screen - 1, clipboard });
            }
        }

        time++; // 1초가 걸리므로 시간을 증가
    }

    return -1; // 도달할 수 없는 경우
}

int main() {
    cin >> S;
    cout << bfs(S) << endl;
    return 0;
}