#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1,-1);
    
    for(auto &cur : edge)
    {
        int a = cur[0];
        int b = cur[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int next : graph[curr])
        {
            if(dist[next] == -1)
            {
                q.push(next);
                dist[next] = dist[curr] + 1; 
            }

        }
    }
    
    int cnt = *max_element(dist.begin(),dist.end());
    
    int answer = count_if(dist.begin(), dist.end(), [cnt](int d) {
        return d == cnt;
    });
    
    return answer;
}