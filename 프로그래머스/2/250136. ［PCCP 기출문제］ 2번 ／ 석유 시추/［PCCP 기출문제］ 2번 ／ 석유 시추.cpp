#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>

using namespace std;

vector<vector<int>> maps;
map<int, int> cnt;
int visited[501][501];
int n, m;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int depth = 1;

void BFS(int x, int y) {
    int tmp = 0;
    queue<pair<int, int>> q;
    q.push({ x, y });
    maps[x][y] = depth;
    visited[x][y] = 1;

    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        tmp++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int curX = tempX + dx[i];
            int curY = tempY + dy[i];

            if (curX < 0 || curY < 0 || curX >= n || curY >= m || visited[curX][curY] || maps[curX][curY] == 0) continue;
            maps[curX][curY] = depth;
            visited[curX][curY] = 1;
            q.push({ curX, curY });
        }
    }

    cnt[depth++] = tmp; 
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size(); 
    m = land[0].size(); 
    memset(visited, 0, sizeof(visited)); 

    maps = land;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && maps[i][j] > 0)
                BFS(i, j);
        }
    }

    for (int i = 0; i < m; i++) {
        int temp = 0;
        set<int> set; 
        for (int j = 0; j < n; j++) {
            set.insert(maps[j][i]);
        }
        for (auto cursor : set) {
            temp += cnt[cursor];
        }
        answer = max(answer, temp);
    }
    return answer;
}