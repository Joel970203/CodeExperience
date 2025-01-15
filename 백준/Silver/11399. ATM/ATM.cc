#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> people;
int N, K, P;
int answer = 0;
int main()
{
	cin >> N;
	P = N;
	while (N--)
	{
		cin >> K;
		people.push_back(K);
	}

	sort(people.begin(), people.end());

	for (int i = 0; i < people.size(); i++)
	{
		answer = answer + people[i] * P;
		P--;
	}
	cout << answer << endl;
}