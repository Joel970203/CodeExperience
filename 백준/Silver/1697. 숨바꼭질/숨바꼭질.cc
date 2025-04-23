#include <iostream>
#include <queue>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

int N, K;
vector<bool> visited; // 방문 여부를 체크하는 벡터
queue<pair<int, int>> q;
int temp;
int walk[3] = { 1, -1, 2 };

int main() {
    fastio();
    cin >> N >> K;

    // 최대 범위를 100000으로 설정하여 모든 경우를 커버
    visited.resize(100001, false);

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == K) {
            cout << y << endl;
            return 0;
        }

        for (int i = 0; i < 3; i++) {
            if (i == 2) {
                temp = x * walk[i];
            }
            else {
                temp = x + walk[i];
            }

            if (temp >= 0 && temp <= 100000 && !visited[temp]) {
                q.push({ temp, y + 1 });
                visited[temp] = true;
            }
        }
    }
    return 0;
}
