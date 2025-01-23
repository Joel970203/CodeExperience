#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1);
	vector<int> order;
	
	for (int i = 1; i <= M; i++)
	{
		int cnt;
		cin >> cnt;
		vector<int> temp(cnt);
		for (int j = 0; j < cnt; j++)
		{
			cin >> temp[j];
		}

		for (int j = 0; j < temp.size(); j++)
		{
			for (int k = j+1; k < temp.size(); k++)
			{
				graph[temp[j]].push_back(temp[k]);
				indegree[temp[k]]++;
			}

		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}


	while (!q.empty())
	{
		int temp = q.front();
		order.push_back(temp);
		q.pop();

		for (auto cur : graph[temp])
		{
			indegree[cur]--;

			if (indegree[cur] == 0)
			{
				q.push(cur);
			}
		}
	}

	if (order.size() != N)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < order.size(); i++)
	{
		cout << order[i] << endl;
	}

	return 0;
}