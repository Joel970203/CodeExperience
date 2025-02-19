#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	string king;
	cin >> N >> M;
	cin >> king;

	unordered_map<string, double> blood;
	unordered_map<string, vector<string>> family;
	unordered_map<string, int> indegree;
	queue<string> q;
	vector<string> candidates(M);

	indegree[king] = 0;
	blood[king] = 1.0;

	for (int i = 0; i < N; i++)
	{
		string child, parent1, parent2;
		cin >> child >> parent1 >> parent2;

		family[parent1].push_back(child);
		family[parent2].push_back(child);

		indegree[child] += 2;

		if (indegree.find(parent1) == indegree.end()) indegree[parent1] = 0;
		if (indegree.find(parent2) == indegree.end()) indegree[parent2] = 0;
	}

	for (int i = 0; i < M; i++) {

		cin >> candidates[i];
	}
	for (auto& cur : indegree)
	{
		if (cur.second == 0)
		{
			q.push(cur.first);
		}
	}

	while (!q.empty())
	{
		string temp = q.front();
		q.pop();

		for (const string& child : family[temp])
		{
			blood[child] += blood[temp] / 2.0;
			indegree[child]--;
			if (indegree[child] == 0)
			{
				q.push(child);
			}
		}
	}

	string next_king;
	double true_blood = -1.0;

	for (const string& next : candidates)
	{
		if (blood[next] > true_blood)
		{
			true_blood = blood[next];
			next_king = next;
		}
	}

	cout << next_king << "\n";
	return 0;
}