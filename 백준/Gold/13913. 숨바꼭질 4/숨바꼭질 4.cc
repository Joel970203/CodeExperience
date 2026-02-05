#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<bool> visited(100001, false);
vector<int> parent(100001, -1);

void BFS(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		auto location = q.front();
		q.pop();
		if (location == end) break;

		for (const auto& next : { location + 1,location - 1, location * 2 })
		{
			if (visited[next] == false && next >= 0 && next <= 100000)
			{
				visited[next] = true;
				q.push(next);
				parent[next] = location;
			}
		}
	}

	vector<int> answer;

	int temp = end;
	while (temp != -1) 
	{
		answer.push_back(temp);
		temp = parent[temp];
	}

	reverse(answer.begin(), answer.end());

	cout << answer.size() - 1 << "\n";
	for (int p : answer) cout << p << " ";
}

int main()
{
	int N, K;
	cin >> N >> K;

	if (N == K) {
		cout << 0 << "\n" << N;
		return 0;
	}

	BFS(N,K);

	return 0;
}