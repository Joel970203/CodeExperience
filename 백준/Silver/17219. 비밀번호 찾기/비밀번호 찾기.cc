#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
	fastio();
	int N, M;
	cin >> N >> M;
	unordered_map<string, string> list;
	for (int i = 0; i < N; i++)
	{
		string a, b;
		cin >> a;
		cin >> b;
		list[a] = b;
	}

	for (int i = 0; i < M; i++)
	{
		string c;
		cin >> c;
		cout << list[c] << endl;
	}
}