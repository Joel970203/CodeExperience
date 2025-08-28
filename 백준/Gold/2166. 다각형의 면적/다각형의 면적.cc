#include <vector>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<long long, long long>> points;

	for(int i=0;i<N;i++)
	{
		int a, b;
		cin >> a >> b;
		points.push_back({ a,b });
	}


	long long sum1 = 0;
	long long sum2 = 0;

	for (int i = 0; i < N; i++) 
	{
		int j = (i + 1) % N; 
		sum1 += points[i].first * points[j].second;
		sum2 += points[i].second * points[j].first;
	}

	double area = abs(sum1 - sum2) / 2.0;
	cout << fixed << setprecision(1) << area << endl;

	return 0;
}