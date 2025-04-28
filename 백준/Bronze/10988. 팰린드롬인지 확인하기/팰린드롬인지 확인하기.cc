#include<iostream>
using namespace std;
int main() 
{
	string input;
	cin >> input;
	for (int i = 0; i < input.length() / 2; ++i)
	{
		if (input[i] != input[input.length() - 1 - i])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}