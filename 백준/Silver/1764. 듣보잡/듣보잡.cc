#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	unordered_map<string, int> map;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		map[temp]++;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		map[temp]++;
	}

	int cnt = 0;
	vector<string> k;

	for (const auto& cur : map)
	{
		if (cur.second > 1)
		{
			cnt++;
			k.push_back(cur.first);
		}
	}

	cout << cnt << endl;
	
	sort(k.begin(), k.end());

	for (int i = 0; i < k.size(); i++)
	{
		cout << k[i] << endl;
	}
}