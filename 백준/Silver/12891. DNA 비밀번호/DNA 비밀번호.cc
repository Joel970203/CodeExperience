#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int S, P;
	int A, C, G, T;
	int cnt = 0;
	char k;
	cin >> S >> P;
	vector<char> DNA(S);
	unordered_map<char, int> map;
	unordered_map<char, int> temp;
	for (int i = 0; i < S; i++)
	{
		cin >> k;
		DNA[i] = k;
	}
	
	cin >> A >> C >> G >> T;

	map['A'] = A;
	map['C'] = C;
	map['G'] = G;
	map['T'] = T;

	// 초기 윈도우
	for (int i = 0; i < P; i++)
	{
		char U = DNA[i];
		temp[U]++;
	}

	auto isValid = [&]() {
		return temp['A'] >= map['A'] &&
		       temp['C'] >= map['C'] &&
		       temp['G'] >= map['G'] &&
		       temp['T'] >= map['T'];
	};

	if (isValid())
	{
		cnt++;
	}

	for (int end = P; end < S; end++)
	{
		char U = DNA[end];
		char O = DNA[end - P];
		temp[U]++;
		if (temp[O] > 0) {
			temp[O]--;
		}

		if (isValid())
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}
