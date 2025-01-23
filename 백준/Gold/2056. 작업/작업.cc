#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> time(N + 1);
	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1);
	vector<int> completionTime(N + 1, 0);
	for (int i = 1; i <= N; i++) // 걸리는시간 , 선행작업 갯수, 선행작업 이름 
	{
		int t, p;
		cin >> t >> p;
		time[i] = t;
		for (int j = 0; j < p; j++)
		{
			int v;
			cin >> v;
			graph[v].push_back(i);
			indegree[i]++;
		}
	}


	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			completionTime[i] = time[i];
		}
	}

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (auto edge : graph[temp])
		{
			completionTime[edge] = max(completionTime[edge], completionTime[temp] + time[edge]);
			indegree[edge]--;

			if (indegree[edge] == 0)
			{
				q.push(edge);
			}
		}
	}

	int total = 0;
	for (int i = 1; i <= N; i++) 
	{
		total = max(total, completionTime[i]);
	}

	cout << total << endl;
}