#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	// 백만개
	// 범위는 -10억 ~ 10억 (int)

	// N^2 불가능.
	
	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> temp = arr;
	sort(temp.begin(), temp.end());
	unordered_map<int, int> map;
	
	int recent = temp[0];
	int key = 0;
	map[recent] = 0;
	for (int i = 1; i < temp.size(); i++)
	{
		if (temp[i] > recent) // 전 숫자보다 클때 
		{
			recent = temp[i];
			key++;
			map[temp[i]] = key;
		}

		else
		{
			map[temp[i]] = key;
		}
		
	}

	for (int i = 0; i < N; i++)
	{
		cout << map[arr[i]] << " ";
	}

	return 0;
}