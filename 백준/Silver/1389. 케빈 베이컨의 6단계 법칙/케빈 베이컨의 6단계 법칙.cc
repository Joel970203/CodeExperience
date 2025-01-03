#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> graph;

int bfs(int start)
{
    vector<int> dist(N + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    int total = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for (int next : graph[current])
        {
            if (dist[next] == -1) // 방문 안한경우
            {
                dist[next] = dist[current] + 1;
                total += dist[next];
                q.push(next);
            }
        }

    }

    return total;

}
int main() {
    cin >> N >> M;
    graph.resize(N + 1); // 유저 번호는 1부터 시작하므로 N+1 크기로 설정

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_bacon = 1e9;
    int result_user = -1;

    for (int i = 1; i <= N; i++) {
        int bacon = bfs(i); // 각 유저의 Kevin Bacon 수 계산
        if (bacon < min_bacon) {
            min_bacon = bacon;
            result_user = i;
        }
    }

    cout << result_user << endl; // Kevin Bacon 수가 가장 작은 유저 출력
    return 0;
 
}