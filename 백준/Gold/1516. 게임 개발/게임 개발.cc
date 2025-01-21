#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1);
	vector<int> time(N + 1);
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		while (1)
		{
			int a;
			cin >> a;
			if (a == -1)
			{
				break;
			}

			if (cnt == 0) // 시간인경우
			{
				cnt++;
				time[i] = a;
			}

			else
			{
				cnt++;
				graph[a].push_back(i);
				indegree[i]++;
			}
		}

	}

	queue<int> q;
	
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			dp[i] = time[i];
		}
	}


	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int next : graph[curr])
		{
			dp[next] = max(dp[next], dp[curr] + time[next]);
			indegree[next]--;

			if (indegree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	for (int i = 1; i < dp.size(); i++)
	{
		cout << dp[i] << endl;
	}

}