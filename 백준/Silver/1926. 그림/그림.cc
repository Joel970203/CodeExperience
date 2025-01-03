#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<int>> graph(501, vector<int>(501));
bool visited[501][501] = { 0 };
int n, m;

int dfs(int x, int y) {
    visited[x][y] = true;
    int area = 1; 

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && graph[nx][ny] == 1) {
            area += dfs(nx, ny); 
        }
    }

    return area;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int numberOfPictures = 0;  
    int maxArea = 0;        

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                numberOfPictures++;
                int area = dfs(i, j); 
                if (area > maxArea) {
                    maxArea = area; 
                }
            }
        }
    }

    cout << numberOfPictures << endl;
    cout << maxArea << endl;

    return 0;
}
