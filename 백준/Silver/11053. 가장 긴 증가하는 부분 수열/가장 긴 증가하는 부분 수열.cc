#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vec.push_back(k);
    }

    vector<int> dp(n,1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}
