#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[101][101]; // 방문 배열
int dx[4] = {1, -1, 0, 0}; // 동서남북 (시계방향)
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y, const vector<string>& board) {
    int sizeX = board[0].size();
    int sizeY = board.size();
    
    // 방문 배열 초기화 (방문하지 않은 곳은 -1)
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            visited[i][j] = -1; // -1은 방문하지 않았다는 의미
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 0; // 시작 지점 방문 처리
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int curX = cur.first;
            int curY = cur.second;
            
            // 한 방향으로 계속 전진
            int nx = curX;
            int ny = curY;
            
            // 한 방향으로 전진
            while (true) {
                nx += dx[i];
                ny += dy[i];
                
                // 범위를 벗어나거나 장애물에 부딪히면 멈춤
                if (nx < 0 || ny < 0 || nx >= sizeY || ny >= sizeX || board[nx][ny] == 'D') {
                    break;
                }
            }

            // 벽 또는 장애물에 부딪힌 이전 좌표로 되돌리기
            nx -= dx[i];
            ny -= dy[i];
            
            // 만약 목표인 'G'를 발견하면 현재까지의 이동 횟수 반환
            if (board[nx][ny] == 'G') {
                return visited[curX][curY] + 1;
            }

            // 아직 방문하지 않은 곳이라면 큐에 추가
            if (visited[nx][ny] == -1) {
                visited[nx][ny] = visited[curX][curY] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1; // 목표에 도달할 수 없는 경우
}

int solution(vector<string> board) {
    int x, y;
    
    // 시작 위치 ('R') 찾기
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
    }

    // bfs 실행
    int answer = bfs(x, y, board);
    return answer;
}
