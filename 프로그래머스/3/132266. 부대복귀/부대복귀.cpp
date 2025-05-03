#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<vector<int>> graph(n + 1);
    
    for (auto& road : roads)
    {
        int u = road[0];
        int v = road[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : graph[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    vector<int> answer;
    for (int src : sources) {
        answer.push_back(dist[src]);
    }
    return answer;
}
