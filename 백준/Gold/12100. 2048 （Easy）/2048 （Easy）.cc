#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int maxSu = INT_MIN;
int N;

vector<int> bubble(vector<int> temp) /// 4 4 4 0
{
	vector<int> line;
	vector<int> answer;
	for (int i = 0; i < N; i++)
	{
		if (temp[i] != 0) line.push_back(temp[i]); 
	}

	for (int i = 0; i < line.size(); i++)
	{
		if (i+1 < line.size() && line[i] == line[i + 1])
		{
			answer.push_back(line[i]*2);
			i++;
		}
		else
		{
			answer.push_back(line[i]);
		}
	}

	while (answer.size() < N) answer.push_back(0);
	return answer;
}

void moveUp(vector<vector<int>> &graph)
{
	for (int j = 0; j < N; j++)
	{
		vector<int> temp;
		for (int i = 0; i < N; i++)
		{
			temp.push_back(graph[i][j]);
		}
		temp = bubble(temp);
		for (int i = 0; i < N; i++) graph[i][j] = temp[i];
	}
}

void moveDown(vector<vector<int>>& graph)
{
	for (int j = 0; j < N; j++)
	{
		vector<int> temp;
		for (int i = N-1; i >= 0; i--)
		{
			temp.push_back(graph[i][j]);
		}
		temp = bubble(temp);
		for (int i = N-1, k=0; i >= 0; i--,k++) graph[i][j] = temp[k];
	}
}

void moveLeft(vector<vector<int>>& graph)
{
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			temp.push_back(graph[i][j]);
		}
		temp = bubble(temp);
		for (int j = 0; j < N; j++) graph[i][j] = temp[j];
	}
}

void moveRight(vector<vector<int>>& graph)
{
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = N - 1; j >= 0; j--)
		{
			temp.push_back(graph[i][j]);
		}
		temp = bubble(temp);
		for (int j = N - 1,k=0; j >= 0; j--,k++) graph[i][j] = temp[k];
	}
}

void backTracking(int cnt,vector<vector<int>> graph)
{
	if (cnt == 5)
	{
		for (auto &row : graph)
		{
			for (int g : row)
			{
				maxSu = max(maxSu, g);
			}
		}

		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		vector<vector<int>> next = graph;
		if (i == 0) moveUp(next);
		else if (i == 1) moveRight(next);
		else if (i == 2) moveLeft(next);
		else if (i == 3) moveDown(next);

		backTracking(cnt + 1, next);
	}

}

int main()
{
	cin >> N;
	vector<vector<int>> graph(N,vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> graph[i][j];
		}
	}

	backTracking(0, graph);

	cout << maxSu << endl;
	return 0;

}