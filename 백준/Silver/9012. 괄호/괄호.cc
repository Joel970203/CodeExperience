#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(void)
{
	int a;
	cin >> a;
	while (a--)
	{
		string arr;
		stack<char> s;
		bool flag = false;
		cin >> arr;
		for (char b : arr)
		{
			if (b == '(')
			{
				s.push('(');
			}
			else if (s.empty())
			{
				flag = true;
				cout << "NO" << endl;
				break;
			}
			else s.pop();
		}
		if (!flag)
		{
			if (s.empty()) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}