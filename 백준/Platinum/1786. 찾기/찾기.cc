#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> getPi(const string& str)
{
    int len = str.length();
    vector<int> pi(len, 0);

    int j = 0;
    for (int i = 1; i < len; i++)
    {
        while (j > 0 && str[i] != str[j]) j = pi[j - 1];
        if (str[i] == str[j]) pi[i] = ++j;
    }

    return pi;
}



vector<int> kmp(const string& t, const string& p)
{
    auto pi = getPi(p);
    int n = t.size(), m = p.size();
    vector<int> answer;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];

        if (t[i] == p[j])
        {
            if (j == m - 1)
            {
                answer.push_back(i - m + 2);
                j = pi[j];
            }

            else j++;
        }
    }

    return answer;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    auto res = kmp(T, P);
    cout << res.size() << "\n";
    for (int x : res) cout << x << " ";
}
