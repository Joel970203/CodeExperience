#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> alphabet(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        alphabet[s[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }
}