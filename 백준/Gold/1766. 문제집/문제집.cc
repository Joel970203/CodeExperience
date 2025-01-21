#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);
    vector<int> arr;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;  
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int curr = pq.top();  
        pq.pop();
        arr.push_back(curr);  

        for (int next : graph[curr])
        {
            indegree[next]--; 
            if (indegree[next] == 0)
            {
                pq.push(next); 
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
