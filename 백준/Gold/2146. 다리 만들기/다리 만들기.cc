#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
            cin >> A[y][x];

    // 1) 섬 라벨링 (1,2,3,...) : label[y][x] = 섬 번호(바다는 0)
    vector<vector<int>> label(N, vector<int>(N, 0));
    int id = 0;
    for (int sy = 0; sy < N; ++sy) {
        for (int sx = 0; sx < N; ++sx) {
            if (A[sy][sx] == 1 && label[sy][sx] == 0) {
                ++id;
                queue<pair<int,int>> q;
                q.push({sy, sx});
                label[sy][sx] = id;
                while (!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        if (A[ny][nx] == 1 && label[ny][nx] == 0) {
                            label[ny][nx] = id;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }

    // 2) 멀티소스 BFS: 각 섬의 "경계"에서 바다로 동시에 확장
    // dist[y][x] : 그 칸을 소유한 섬으로부터의 바다 거리 (섬 내부는 0)
    // owner[y][x]: 그 칸을 최초로 차지한 섬 번호(0=아직 미방문 바다)
    vector<vector<int>> dist(N, vector<int>(N, -1));
    vector<vector<int>> owner(N, vector<int>(N, 0));
    queue<pair<int,int>> q;

    // 모든 섬의 경계(혹은 전체 땅)에서 시작: 섬 내부 dist=0, owner=섬번호
    // 경계만 넣으면 큐가 더 작아집니다. (아래는 경계만 push 하는 버전)
    auto isSeaNeighbor = [&](int y, int x) {
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (A[ny][nx] == 0) return true;
        }
        return false;
    };

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (A[y][x] == 1) {
                if (isSeaNeighbor(y, x)) {
                    dist[y][x]  = 0;
                    owner[y][x] = label[y][x];
                    q.push({y, x});
                } else {
                    // 경계가 아니어도 owner/dist를 기록해두면 로직상 안전합니다.
                    owner[y][x] = label[y][x];
                    dist[y][x]  = 0;
                }
            }
        }
    }

    int ans = INT_MAX;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            // 바다로만 퍼뜨린다
            if (A[ny][nx] == 0) {
                if (owner[ny][nx] == 0) { 
                    // 아직 아무 섬도 차지하지 않은 바다
                    owner[ny][nx] = owner[y][x];
                    dist[ny][nx]  = dist[y][x] + 1;
                    q.push({ny, nx});
                } else if (owner[ny][nx] != owner[y][x]) {
                    // 이미 다른 섬이 차지한 바다를 만남 → 두 섬 사이 다리 길이 후보
                    ans = min(ans, dist[ny][nx] + dist[y][x]);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
