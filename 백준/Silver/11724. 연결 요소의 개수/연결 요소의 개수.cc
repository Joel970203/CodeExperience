#include <iostream>
#include <vector>
using namespace std;

vector<int> vect[1001]; //인접리스트
int visited[1001];      //방문기록
int N, M;

/* DFS : 방문기록 남기는 용도 */
void DFS(int vertex)
{
    visited[vertex] = 1;
    for (int i = 0; i < vect[vertex].size(); i++) //최댓값 주의 : 벡터 그 원소에 해당하는 크기만큼 돌아야함
    {
        int idx = vect[vertex][i];
        if (visited[idx] == 0)
        {
            DFS(idx);
        }
    }
}

int main()
{
    int u, v;
    int cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u); //무방향 그래프이기 때문
    }

    for (int i = 1; i <= N; i++) //빠짐없이 탐색하기 위해
    {
        if (visited[i] == 0)
        {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << "\n";
}