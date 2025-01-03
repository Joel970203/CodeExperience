#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
vector<int> visited(100001, 0); // 방문 여부 + 최단 시간 기록
vector<int> ways(100001, 0);    // 해당 위치에 도달하는 방법의 수

void bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = 1; // 수빈이가 처음 위치한 곳은 0초에 방문
    ways[N] = 1;    // 수빈이가 시작 위치로 도달하는 방법은 1가지

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 3가지 이동 방식 (현재 위치 + 1, -1, *2)
        for (int next : {current + 1, current - 1, current * 2}) {
            // 범위를 벗어나지 않으면
            if (next >= 0 && next <= 100000) {
                // 처음 방문하는 위치라면
                if (visited[next] == 0) {
                    visited[next] = visited[current] + 1; // 시간을 기록
                    ways[next] = ways[current]; // 방법의 수를 초기화
                    q.push(next); // 큐에 넣음
                }
                // 이미 방문한 위치지만, 빠른 시간으로 방문할 수 있다면
                else if (visited[next] == visited[current] + 1) { 
                    ways[next] += ways[current]; // 방법의 수를 추가
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;

    // 수빈이가 동생과 같은 위치에 있다면 0초로 바로 출력
    if (N == K) {
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    bfs();

    // 동생 위치에서 최단 시간과 방법의 수 출력
    cout << visited[K] - 1 << endl; // 시간을 출력 (visited는 1초부터 기록되므로 1을 빼야 함)
    cout << ways[K] << endl;         // 방법의 수 출력

    return 0;
}