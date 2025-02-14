#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> arr;      
vector<char> password; 
vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

bool is_valid() 
{
    int vowel_count = 0, consonant_count = 0;
    for (char c : password)
    {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end())
            vowel_count++;
        else
            consonant_count++;
    }
    return vowel_count >= 1 && consonant_count >= 2;
}

void dfs(int index)
{
    if (password.size() == L)
    { 
        if (is_valid()) 
        { 
            for (char c : password) cout << c;
            cout << '\n';
        }
        return;
    }

    for (int i = index; i < C; i++)
    {
        password.push_back(arr[i]); 
        dfs(i + 1); 
        password.pop_back();
    }
}

int main() 
{
    cin >> L >> C;
    arr.resize(C);

    for (int i = 0; i < C; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    dfs(0); 
}
