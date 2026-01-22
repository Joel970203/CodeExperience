#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;
int conquer = 0;
int tot = 0;
/*
너비 우선 탐색인데, q size에 따라 일수를 체크해야할 문제입니다.
입력값은 따로 체크할 필요가 없을듯. (1000이하)
인데, 풀다가 착각한게 토마토는 한군데가 아니라 여러곳에 있을수있는걸 생각해야함

*/

int BFS(const vector<pair<int,int>> &start)
{
	queue<pair<int, int>> q;
	int sz = start.size();
	for (int i = 0; i < sz; ++i)
	{
		q.push({ start[i].first,start[i].second });
		tot++;
	}

	while (!q.empty())
	{
		int qsize = q.size();

		while (qsize--)
		{
			auto [y, x] = q.front(); q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int curY = y + dy[i];
				int curX = x + dx[i];

				if (curY >= 0 && curY < N && curX >= 0 && curX < M)
				{
					if (!visited[curY][curX] && arr[curY][curX] == 0)
					{
						q.push({ curY,curX });
						tot++;
						visited[curY][curX] = 1;
					}
				}
			}
		}

		if (q.empty()) break;
		ans++;
	}

	return ans;
}
int main()
{
	vector<pair<int, int>> start;
	cin >> M >> N;
	arr.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));
	conquer = M * N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int k;
			cin >> k;
			arr[i][j] = k;
			if (k==1)
			{
				start.push_back({ i,j });
			}

			if (k == -1) conquer--;
		}
	}


	int tmp = BFS(start);
	
	if (tot == conquer) cout << tmp << endl;
	else cout << -1 << endl;

	return 0;

}