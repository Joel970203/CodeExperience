#include <iostream>
#include <vector>

using namespace std;

int ans = -1;

void DFS(int i,const vector<vector<int>> &arr,vector<bool> &visited)
{
	if (visited[i]) return;

	ans++;
	visited[i] = true;

	for (int j = 0; j < (int)arr[i].size(); ++j)
	{
		DFS(arr[i][j], arr, visited);
	}
}


int main()
{
	int N, M;
	cin >> N;
	cin >> M;

	vector<vector<int>> arr(N+1);
	vector<bool> visited(N+1, false);

	for (int i = 0; i < M; i++)
	{
		int k, l;
		cin >> k >> l;

		arr[k].push_back(l);
		arr[l].push_back(k);
	}

	DFS(1, arr, visited);
	cout << ans << endl;
	return 0;
}