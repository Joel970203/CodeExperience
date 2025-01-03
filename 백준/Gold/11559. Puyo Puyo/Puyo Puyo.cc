#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

bool visited[12][6];  
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> stk;  // 터지는 뿌요들의 위치를 저장하는 스택
int ans = 0;  // 연쇄 횟수를 저장


bool bfs(int x, int y, vector<vector<char>>& field) {
    queue<pair<int, int>> q;
    stk.clear();  
    q.push({ x, y });
    stk.push_back({ x, y });
    visited[x][y] = true;
    char color = field[x][y]; 

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            // 범위 내에 있고, 방문하지 않았으며, 같은 색의 뿌요일 경우
            if (newX >= 0 && newX < 12 && newY >= 0 && newY < 6 && !visited[newX][newY] && field[newX][newY] == color) {
                visited[newX][newY] = true;
                q.push({ newX, newY });
                stk.push_back({ newX, newY });  // 터질 뿌요의 위치를 저장
            }
        }
    }

    // 만약 4개 이상의 뿌요가 모이면 터뜨림
    if (stk.size() >= 4) {
        for (auto& cur : stk) {
            field[cur.first][cur.second] = '.';  // 뿌요를 터뜨려서 빈 공간으로 만듦
        }
        return true;  // 터진 뿌요가 있음을 반환
    }
    return false;  // 터질 수 있는 뿌요가 없음을 반환
}

// 터진 후 뿌요들을 아래로 내리는 함수
void dropPuyos(vector<vector<char>>& field) {
    for (int i = 0; i < 6; i++) {  
        int emptyRow = 11;  // 가장 아래부터 비어 있는 칸을 추적
        for (int j = 11; j >= 0; j--) {
            if (field[j][i] != '.') {  
                swap(field[emptyRow][i], field[j][i]);  
                emptyRow--;  // 비어 있는 칸 위치를 한 칸 위로 이동
            }
        }
    }
}

int main() {
    fastio();
    vector<vector<char>> field(12, vector<char>(6));  
    char value;

    // 필드 입력 받기
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> value;
            field[i][j] = value;
        }
    }

    bool chain = false;  // 연쇄가 일어났는지 확인하는 변수

    do {
        chain = false;  // 이번 턴에서 연쇄가 발생했는지 여부를 확인
        fill(&visited[0][0], &visited[0][0] + 12 * 6, false);  // 방문 배열 초기화

        // 필드 전체를 순회하면서 뿌요가 있는 곳에서 BFS를 수행
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (field[i][j] != '.' && !visited[i][j]) {
                    // 만약 터질 수 있는 뿌요가 있다면
                    if (bfs(i, j, field)) {
                        chain = true;  // 연쇄 발생
                    }
                }
            }
        }

        // 뿌요가 터졌다면 뿌요를 아래로 내림
        if (chain) {
            dropPuyos(field);
            ans++;  // 연쇄 횟수를 증가시킴
        }
    } while (chain);  // 연쇄가 발생하는 동안 계속 반복

    // 연쇄 횟수 출력
    cout << ans << endl;

    return 0;
}