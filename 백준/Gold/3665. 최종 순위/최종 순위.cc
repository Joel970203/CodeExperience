#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int T, n, m;

    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<int> last_rank(n);
        vector<int> indegree(n + 1);
        vector<vector<int>> graph(n + 1); 

        for (int i = 0; i < n; i++)
        {
            cin >> last_rank[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                graph[last_rank[i]].push_back(last_rank[j]);
                indegree[last_rank[j]]++;
            }
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            if (find(graph[a].begin(), graph[a].end(), b) != graph[a].end()) // a가 b보다 앞선 순위였던 경우
            {
                graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
                graph[b].push_back(a);
                indegree[b]--;
                indegree[a]++;
            }
            else
            {
                graph[b].erase(find(graph[b].begin(), graph[b].end(), a));
                graph[a].push_back(b);
                indegree[a]--;
                indegree[b]++;
            }
        }

        queue<int> q;
        vector<int> result;

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        bool ambiguous = false;
        bool impossible = false;

        for (int i = 0; i < n; i++)
        {
            if (q.empty()) 
            {
                impossible = true;
                break;
            }

            if (q.size() > 1) 
            {
                ambiguous = true;
            }

            int cur = q.front();
            q.pop();
            result.push_back(cur);

            for (int next : graph[cur])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        if (impossible)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else if (ambiguous)
        {
            cout << "?" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }
}
