#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

// 좌표를 나타내는 구조체
struct Point {
    int x;
    int y;
};

// 맥주를 파는 편의점, 페스티벌, 집의 좌표 저장
vector<Point> stores;
Point festival;
Point home;

// BFS 탐색 함수
bool BFS(int n) {
    vector<bool> visited(n, false); // 방문 체크 배열
    queue<Point> q;               // BFS를 위한 큐
    q.push(home);                 // 큐에 시작점(집) 추가

    while (!q.empty()) {
        Point current = q.front(); // 현재 위치
        q.pop();

        // 현재 위치에서 페스티벌까지의 거리 계산
        if (abs(festival.x - current.x) + abs(festival.y - current.y) <= 1000) {
            return true; // 페스티벌에 도착할 수 있으면 true 반환
        }

        // 각 편의점을 확인
        for (int i = 0; i < n; i++) {
            // 방문하지 않은 편의점인지 확인
            if (!visited[i]) {
                // 현재 위치에서 해당 편의점까지의 거리 계산
                if (abs(stores[i].x - current.x) + abs(stores[i].y - current.y) <= 1000) {
                    visited[i] = true;                // 방문한 편의점으로 체크
                    q.push(stores[i]);              // 큐에 편의점 추가
                }
            }
        }
    }
    return false; // 모든 경로를 탐색했으나 도착하지 못했으면 false 반환
}

int main() {
    int t; // 테스트 케이스 개수
    cin >> t;

    while (t--) {
        int n; // 편의점 개수
        cin >> n;

        // 집 좌표 입력
        cin >> home.x >> home.y;
        stores.resize(n); // 편의점 개수에 맞게 크기 조정
        for (int i = 0; i < n; i++) {
            cin >> stores[i].x >> stores[i].y; // 편의점 좌표 입력
        }
        // 페스티벌 좌표 입력
        cin >> festival.x >> festival.y;

        // BFS 탐색 실행
        bool possible = BFS(n);
        if (possible)
            cout << "happy\n"; // 도착 가능
        else
            cout << "sad\n"; // 도착 불가능
    }

    return 0;
}