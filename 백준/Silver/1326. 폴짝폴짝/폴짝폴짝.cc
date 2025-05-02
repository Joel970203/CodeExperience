#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, a, b;
	cin >> N;
	vector<int> arr(N + 1);
	vector<int> visited(N + 1, -1);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	cin >> a >> b;

	queue<int> q;
	q.push(a);
	visited[a] = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		int step = arr[current];

		for (int k = 1; current + step * k <= N; k++)
		{
			int next = current + step * k;
			if (visited[next] == -1)
			{
				visited[next] = visited[current] + 1;
				q.push(next);
			}
		}
		for (int k = 1; current - step * k >= 1; k++)
		{
			int next = current - step * k;
			if (visited[next] == -1)
			{
				visited[next] = visited[current] + 1;
				q.push(next);
			}
		}
	}

	cout << visited[b] << "\n";
	return 0;
}
