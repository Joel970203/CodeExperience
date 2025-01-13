#include <iostream>
#include <vector>

using namespace std;

vector<int> depth;
vector<int> root;

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

bool bridge(int a,int b)
{
	if (Find(a) == Find(b))
	{
		return false;
	}

	else
	{
		return true;
	}

}


void Union(int x,int y)
{
	int P_x = Find(x);
	int P_y = Find(y);

	if (P_x == P_y)
	{
		return;
	}

	if (depth[P_x] < depth[P_y])
	{
		root[P_x] = y;
	}

	else if (depth[P_y] < depth[P_x])
	{
		root[P_y] = x;
	}

	else if (depth[P_y] == depth[P_x])
	{
		root[P_y] = x;
		depth[x]++;
	}
}

int main()
{
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	depth.resize(N + 1);
	root.resize(N + 1);

	for (int i = 0; i < N; i++)
	{
		depth[i] = 1;
		root[i] = i;
	}

	vector<int> classes(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> classes[i];
	}

	for (int i = 0; i < N-1; i++)
	{
		int k = classes[i];
		int q = classes[i + 1];

		if (bridge(k, q))
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}

