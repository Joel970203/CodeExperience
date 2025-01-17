#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    
    int x = 0, y = 0; // 초기 위치
    int direction = 0; // 0: 아래, 1: 오른쪽, 2: 위 대각선
    int num = 1;

    for (int i = 0; i < n * (n + 1) / 2; i++) {
        triangle[y][x] = num++; 
        if (direction == 0) { // 아래로
            if (y + 1 < n && triangle[y + 1][x] == 0) {
                y++;
            } else {
                direction = 1; // 방향 전환: 오른쪽
                x++;
            }
        } else if (direction == 1) { // 오른쪽으로
            if (x + 1 < n && triangle[y][x + 1] == 0) {
                x++;
            } else {
                direction = 2; // 방향 전환: 위 대각선
                y--;
                x--;
            }
        } else if (direction == 2) { // 위 대각선으로
            if (y - 1 >= 0 && x - 1 >= 0 && triangle[y - 1][x - 1] == 0) {
                y--;
                x--;
            } else {
                direction = 0; // 방향 전환: 아래로
                y++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}