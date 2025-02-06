#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	bool isFirst[10] = { false };
	vector<pair<long long, int>> grade(10);

	for (int i = 0; i < 10; i++)
	{
		grade[i].second = i;
	}

	for(int i=0;i<N;i++)
	{
		string temp;
		cin >> temp;

		isFirst[temp[0] - 'A'] = true;

		for (int j = 0; j < temp.length(); j++)
		{
			grade[temp[j] - 'A'].first += pow(10, temp.length() - j - 1);
		}
	}

	sort(grade.begin(), grade.end(), greater<>());

	if (isFirst[grade[9].second])
	{
		for (int i = 8; i >= 0; i--)
		{
			if (!isFirst[grade[i].second])
			{
				swap(grade[9], grade[i]);
				break;
			}
		}
	}

	sort(grade.begin(), grade.end() - 1, greater<>());

	long long answer = 0;
	int cnt = 9;

	for (int i = 0; i < 10; i++)
	{
		answer += grade[i].first * cnt--;
	}

	cout << answer << endl;
}