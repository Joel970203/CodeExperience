#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<deque<int>> gear(4);


void rotate(int num,int dir)
{
	if (dir == 1)
	{
		char k = gear[num].back();
		gear[num].pop_back();
		gear[num].push_front(k);
	}

	else if (dir == -1)
	{
		char k = gear[num].front();
		gear[num].pop_front();
		gear[num].push_back(k);
	}
}

void wave(int num,int dir)
{
	int direction[4] = { 0,0,0,0 };
	direction[num] = dir;

	for (int i = num; i < 3; i++) 
	{
		if (gear[i][2] != gear[i + 1][6])
		{
			int tmp = -direction[i];
			direction[i + 1] = tmp;
		}
	}

	for (int i = num; i > 0; i--)
	{
		if (gear[i][6] != gear[i - 1][2])
		{
			int tmp = -direction[i];
			direction[i - 1] = tmp;
		}
	}


	for (int i = 0; i < 4; i++)
	{
		if (direction[i] != 0)
		{
			rotate(i, direction[i]);
		}
	}
}

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		string s;
		cin >> s;
		for (const auto& cur : s)
		{
			gear[i].push_back(cur);
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		wave(a-1, b);
	}

	int answer = 0;
	if (gear[0][0] == '1') answer += 1;
	if (gear[1][0] == '1') answer += 2;
	if (gear[2][0] == '1') answer += 4;
	if (gear[3][0] == '1') answer += 8;

	cout << answer;
}