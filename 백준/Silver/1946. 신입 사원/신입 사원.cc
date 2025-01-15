#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;

int main(void)
{

	cin >> a;

	while (a--)
	{
		cin >> b;
		vector<pair<int, int>> grades;

		for (auto i = 0; i < b; i++)
		{
			int x, y;
			cin >> x >> y;
			grades.push_back({ x,y });
		}

		sort(grades.begin(), grades.end());
		int temp = 0;
		int result = 1;

		for (auto i = 1; i < b; i++)
		{
			if (grades[temp].second > grades[i].second)
			{
				result++;
				temp = i;
			}
		}
		cout << result << "\n";
	}
}