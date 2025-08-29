#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> parent(MAX + 1, -1);
    vector<int> dist(MAX + 1, -1);
    queue<int> q;

    q.push(N);
    dist[N] = 0;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == K) break;

        for (auto p : { cur - 1,cur + 1,cur * 2 })
        {
            if (p < 0 || p > 100000) continue;
            if (dist[p] != -1) continue;
            
            dist[p] = dist[cur] + 1;
            parent[p] = cur;
            q.push(p);
        }
    }


    cout << dist[K] << endl;

    vector<int> path;

    for (int i = K; i != -1; i = parent[i])
    {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    return 0;

}
