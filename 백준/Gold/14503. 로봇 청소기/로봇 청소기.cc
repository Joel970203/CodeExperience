#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북, 동, 남, 서
int N, M;
int cleaned = 0;

void clean(int y, int x, int dir) {
    while (true) {
        if (graph[y][x] == 0) { 
            graph[y][x] = 2;
            cleaned++;
        }

        bool found = false;
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4; 
            int ny = y + direction[dir].first;
            int nx = x + direction[dir].second;

            if (graph[ny][nx] == 0) { 
                y = ny;
                x = nx;
                found = true;
                break;
            }
        }

        if (!found) { 
            int backY = y - direction[dir].first;
            int backX = x - direction[dir].second;

            if (graph[backY][backX] == 1) break; 

            y = backY;
            x = backX;
        }
    }
}

int main() {
    cin >> N >> M;
    int y, x, d;
    cin >> y >> x >> d;

    graph.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    clean(y, x, d);
    cout << cleaned << endl;
    return 0;
}
