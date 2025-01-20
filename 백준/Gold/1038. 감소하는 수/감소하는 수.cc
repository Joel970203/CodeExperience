#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> result;

void DFS(long long idx, int cnt) 
{
    if (cnt > 10)
        return;
    result.push_back(idx);
    for (int i = 0; i < 10; i++) 
    {
        if (idx % 10 > i) 
        {
            DFS(idx * 10 + i, cnt + 1);
        }
    }
    return;
}

void Solution() 
{
    for (int i = 0; i < 10; i++) 
    {
        DFS(i, 1);
    }
}

int main() 
{
    cin >> n;
    Solution();
    sort(result.begin(), result.end());

    if (result.size() <= n) {
        cout << "-1" << endl;
    }
    else if (result.size() > n) {
        cout << result[n] << endl;
    }
    return 0;
}