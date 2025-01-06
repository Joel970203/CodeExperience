#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vector<char> q;
vector<int> su;
int total = 0;
bool visited[6][6] = { false };
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };


int dfs(int x, int y,int N,const vector<vector<char>> &graph)
{
	/*
	dfs로 백트래킹 하는 문제 같은데..
	일단 x좌표 +1 or y좌표 +1 만 가능하고,
	stack을 이용하여, 숫자면 push. 
	문자도 push, 이제 top이 문자 인경우, 계산하자
	완성된 값은 리턴. 완성된 값은 어떻게 찾지 ? 
	스택에 계산된 값을 넣지말고, 리턴할때만 계산하자.
	그리고 백트래킹
	*/

	q.push_back(graph[x][y]);

	if (x + 1 == N && y + 1 == N) // 마지막에 도달한 경우 
	{
		int total = q[0] - '0'; // 캐스팅 해줘야함 
		for (int i = 1; i < q.size() - 1; i++)
		{
			if (q[i] == '+')
			{
				total += (q[i + 1] - '0');
			}
			else if (q[i] == '-')
			{
				total -= (q[i + 1] - '0');
			}
			else if (q[i] == '*')
			{
				total *= (q[i + 1] -'0');
			}
		}
		su.push_back(total);
	}
	

	for (int i = 0; i < 2; i++)
	{
		x += dx[i];
		y += dy[i];
		
		if (x >= N || y >= N)
		{
			x -= dx[i];
			y -= dy[i];   
			continue;
		}
		if (x <= N && y <= N && x >= 0 && y >= 0 && visited[x][y] == false)
		{
			visited[x][y] = true;
			dfs(x, y, N, graph);
			q.pop_back();
			visited[x][y] = false;
			x -= dx[i];
			y -= dy[i];
		}
		
	}

	return 0;
}

int main()
{
	fastio();

	int N;

	cin >> N;
	vector<vector<char>> graph(N, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char q;
			cin >> q;
			graph[i][j] = q;
		}
	}

	dfs(0, 0, N, graph);
	sort(su.begin(), su.end(), greater<>());
	int last = su.size() - 1;

	cout << su[0] << " " << su[last];
}