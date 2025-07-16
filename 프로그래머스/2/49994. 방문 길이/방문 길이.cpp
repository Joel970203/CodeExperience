#include <string>
using namespace std;

bool visited[11][11][11][11] = { false };  // from (y1,x1) to (y2,x2)

int solution(string dirs) 
{
    int answer = 0;
    int curY = 5;
    int curX = 5;

    for (char dir : dirs)
    {
        int nextY = curY;
        int nextX = curX;

        if (dir == 'U') nextY--;
        if (dir == 'D') nextY++;
        if (dir == 'L') nextX--;
        if (dir == 'R') nextX++;

        if (nextY < 0 || nextY > 10 || nextX < 0 || nextX > 10)
            continue;

        if (!visited[curY][curX][nextY][nextX]) {
            visited[curY][curX][nextY][nextX] = true;
            visited[nextY][nextX][curY][curX] = true;
            answer++;
        }

        curY = nextY;
        curX = nextX;
    }

    return answer;
}
