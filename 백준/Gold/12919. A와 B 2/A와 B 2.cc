#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool back_track(string S,string T)
{
	if (S.length() == T.length())
	{
		return S == T;
	}

	if (T.back() == 'A')
	{
		string nextT = T;
		nextT.pop_back();
		if(back_track(S, nextT)) return true;
	}

	if(T.front() == 'B') // 뒤가 b인경우 
	{
		string nextT = T;
		reverse(nextT.begin(), nextT.end());
		nextT.pop_back();
		if (back_track(S, nextT)) return true;
	}

	return false;
}

int main()
{
	string S, T;
	cin >> S;
	cin >> T;

	if (back_track(S, T))
	{
		cout << 1 << endl;
	}

	else cout << 0 << endl;

	return 0;


}