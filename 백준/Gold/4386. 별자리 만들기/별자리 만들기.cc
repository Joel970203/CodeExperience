#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

double calcDistance(pair<double, double>& a, pair<double, double>& b)
{
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

double prim(int N, vector<pair<double, double>>& stars)
{
	vector<bool> visited(N, 0);
	vector<double> minDist(N, 1e9);
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

	minDist[0] = 0;
	pq.push({ 0,0 });
	double mstWeight = 0;
	while (!pq.empty())
	{
		double dist = pq.top().first;
		int node = pq.top().second;

		pq.pop();

		if (visited[node] == true) continue;
		visited[node] = true;
		mstWeight += dist;

		for (int next = 0; next < N; next++)
		{
			if (!visited[next])
			{
				double tempDist = calcDistance(stars[node], stars[next]);
				if (tempDist < minDist[next])
				{
					minDist[next] = tempDist;
					pq.push({ tempDist,next });
				}
			}
		}
	}

	return mstWeight;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<double, double>> stars(N);

	for (int i = 0; i < N; i++)
	{
		cin >> stars[i].first >> stars[i].second;
	}

	double result = prim(N, stars);

	cout << fixed << setprecision(2) << result << endl;

	return 0;
}