#include <iostream>
#include <vector>

using namespace std;
vector<int> depth;
vector<int> root;
vector<bool> visited;
vector<int> answer;

int Find(int x)
{
	if (x == root[x])
	{
		return x;
	}

	else
	{
		return root[x] = Find(root[x]);
	}
}

void Union(int x, int y) 
{
	int R_x = Find(x);
	int R_y = Find(y);

	if (R_x == R_y)
		return;

	if (depth[R_x] < depth[R_y]) 
	{
		root[R_x] = R_y;
	}

	else if (depth[R_x] > depth[R_y]) 
	{
		root[R_y] = R_x;
	}
	else 
	{
		root[R_y] = R_x;
		depth[R_x]++;
	}
}


int main()
{
	int N;
	cin >> N;


	depth.resize(N+1);
	root.resize(N + 1);
	visited.resize(N + 1);
	answer.resize(N + 1);
	for(int i=0;i<=N;i++)
	{
		depth[i] = 1;
		root[i] = i;
	}

	for (int i = 0; i < N - 2; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	/*
	연결된지를 어떻게 체크할까 ? 
	root 를 순회하면서, 본인하고 다른애들은 visited에 체크 
	본인하고 다른 마지막끼리 연결 하면되겠다.
	*/

	for (int i = 1; i < root.size(); i++)
	{
		if (root[i] != i)
		{
			visited[i] = true;
		}
	}

	for (int i = 1; i < root.size(); i++)
	{
		if (visited[i] == false)
		{
			answer[i] = i;
			cout << answer[i] << " ";
		}

		
	}

	
}