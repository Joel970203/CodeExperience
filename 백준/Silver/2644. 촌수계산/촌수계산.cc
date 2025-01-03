#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
bool visited[MAX] = { 0 };
int ans = -1;

int dfs(int a, int b, int cnt)
{
    visited[a] = true;

    // 시작점과 목표점이 같으면 촌수를 반환
    if (a == b)
    {
        return cnt;
    }

    // 인접 노드들에 대해 DFS 실행
    for (int i = 0; i < graph[a].size(); i++)
    {
        int next = graph[a][i];
        if (!visited[next])
        {
            int result = dfs(next, b, cnt + 1);
            if (result != -1)  // 경로를 찾으면 결과 반환
                return result;
        }
    }

    // 경로가 없는 경우
    return -1;
}

int main()
{
    int n, a, b, m; // 전체 수 n, 촌수 계산할 두 사람 a, b, 관계 개수 m

    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // DFS 호출 및 결과 출력
    int key = dfs(a, b, 0);

    cout << key << endl;
    return 0;
}