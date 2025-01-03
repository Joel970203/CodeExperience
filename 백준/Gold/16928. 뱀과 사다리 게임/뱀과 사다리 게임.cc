#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> board(101, 0);  // 게임판 1부터 100까지 사용, 각 칸에 이동할 위치 저장
vector<int> dist(101, -1);  // 각 칸에 도달하는데 필요한 주사위 굴림 수 저장

void bfs(int start) {
    queue<int> q;
    dist[start] = 0;  // 시작 지점은 0번 주사위 굴림
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 주사위는 1~6까지의 숫자가 나오므로, 각 경우를 계산
        for (int dice = 1; dice <= 6; dice++) { 
            int next = current + dice;
            if (next > 100) continue;  // 100번 칸을 넘어서면 이동 불가

            // 사다리나 뱀에 의해 이동할 위치가 바뀔 수 있음
            next = board[next];

            // 해당 칸을 아직 방문하지 않았다면, 방문 처리 및 큐에 삽입
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 보드 초기화: 각 칸은 기본적으로 자기 자신으로 이동
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    // 사다리 정보 입력
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        board[x] = y;  // x번 칸에 도착하면 y번 칸으로 이동
    }

    // 뱀 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;  // u번 칸에 도착하면 v번 칸으로 이동
    }

    // BFS를 통해 1번 칸에서 100번 칸으로 가는 최단 경로 계산
    bfs(1);

    // 100번 칸에 도착하는데 필요한 최소 주사위 굴림 횟수 출력
    cout << dist[100] << endl;

    return 0;
}