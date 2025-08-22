#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(const vector<vector<pair<int,int>>> &graph,int start,int V)
{
    vector<int> dist(V+1,1e9);
    dist[start] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,start}); 
    
    while(!pq.empty())
    {
        auto [cost,node] = pq.top();
        pq.pop();
        
        if(cost > dist[node]) continue;
        
        for(auto [w,next] : graph[node])
        {
            if(dist[next] > cost + w )
            {
                dist[next] = cost + w;
                pq.push({dist[next],next});
            }
        }
    }
    
    for(int i=1; i<=V; i++)
    {
        if(dist[i] == 1e9) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main()
{
    int V,E,K;
    cin >> V >> E >> K;
    vector<vector<pair<int,int>>> graph(V+1);
    for(int i=0;i<E;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({w,v});
    }
    
    dijkstra(graph,K,V);
}