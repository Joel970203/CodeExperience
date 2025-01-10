#include <iostream>
#include <vector>
#include <algorithm> // For sorting
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

bool visited[101][101] = { 0 };
vector<vector<int>> cube;
int N, M, K;
int dx[4] = { 1, 0, -1, 0 }; // 상, 하, 좌, 우 방향
int dy[4] = { 0, 1, 0, -1 }; // 상, 하, 좌, 우 방향

int DFS(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y] || cube[x][y] == 1) {
        return 0;
    }

    visited[x][y] = true;
    int area = 1; // 현재 위치도 영역의 일부이므로 1

    // 상하좌우로 이동하면서 영역을 확장
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        area += DFS(nx, ny); // 연결된 모든 0을 탐색
    }

    return area;
}

int main() {
    fastio();

    cin >> N >> M >> K;

    cube.resize(N);
    for (int i = 0; i < N; i++) {
        cube[i].resize(M, 0);
    }

    // 직사각형 영역을 1로 채움
    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int x = a; x < c; x++) {
            for (int y = b; y < d; y++) {
                cube[y][x] = 1; // 직사각형 내부는 1로 채움
            }
        }
    }

    vector<int> areas; // 각 영역의 넓이를 저장할 벡터

    // 모든 칸을 돌면서 방문하지 않은 0인 영역에 대해 DFS 실행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && cube[i][j] == 0) {
                int area = DFS(i, j); // 해당 영역의 넓이를 계산
                areas.push_back(area); // 넓이 저장
            }
        }
    }

    // 영역의 개수와 각 영역의 넓이를 출력
    cout << areas.size() << '\n'; // 분리된 영역의 개수
    sort(areas.begin(), areas.end()); // 넓이를 오름차순으로 정렬
    for (int area : areas) {
        cout << area << ' ';
    }

    return 0;
}