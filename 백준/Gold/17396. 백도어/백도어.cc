#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> arr;
vector<int> sight;


long long dijkstra(int start)
{
    const long long INF = 1e12;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> dist(N, INF);

    if (sight[0] == 1) return -1;

    dist[0] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) continue;

        for (auto& edge : arr[node])
        {
            int val = edge.first;
            int next = edge.second;

            if (sight[next] == 1 && next != N - 1) continue;

            if (dist[next] > cost + val)
            {
                dist[next] = cost + val;
                pq.push({ dist[next], next });
            }
        }
    }

    return (dist[N - 1] == INF ? -1 : dist[N - 1]);
}


int main()
{
	cin >> N >> M;
	arr.resize(N);
	sight.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> sight[i];
	}

	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ w,v });
		arr[v].push_back({ w,u });
	}

	cout << dijkstra(0);

}