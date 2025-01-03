#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> graph(100, vector<int>(100, 0)); 
bool visited[100][100] = { 0 }; 
int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, 1, -1 };

void bfs()
{
    queue<pair<int, int>> q;
    q.push({ 0, 0 }); 
    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 내에 있고 아직 방문하지 않은 경우
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny])
            {
                if (graph[nx][ny] == 0) //탐색 계속
                {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
                else if (graph[nx][ny] == 1) // 치즈면 녹을 예정 표시
                {
                    visited[nx][ny] = true;
                    graph[nx][ny] = 2; // 녹을 치즈 표시
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    int totalCheese = 0; // 전체 치즈 개수

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                totalCheese++; // 초기 치즈 개수 계산
        }
    }

    int time = 0; // 치즈가 녹는 시간
    int lastCheese = 0; // 모두 녹기 전 남은 치즈 개수

    while (totalCheese > 0)
    {
        fill(&visited[0][0], &visited[0][0] + 100 * 100, false); // 방문 초기화
        bfs(); // 외부 공기 탐색 및 치즈 녹이기

        int meltedCheese = 0;

        // 녹은 치즈 처리
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (graph[i][j] == 2) // 녹은 치즈 처리
                {
                    graph[i][j] = 0;
                    meltedCheese++;
                }
            }
        }

        lastCheese = totalCheese; // 현재 남은 치즈 기록
        totalCheese -= meltedCheese; // 전체 치즈에서 녹은 개수 빼기
        time++; // 시간 증가
    }

    cout << time << endl; // 치즈가 모두 녹는 시간
    cout << lastCheese << endl; // 모두 녹기 직전 남은 치즈 개수
}