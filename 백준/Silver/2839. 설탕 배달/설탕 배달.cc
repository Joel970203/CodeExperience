#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> DP(N + 1, -1);

    DP[3] = 1;
    DP[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        if (DP[i - 3] != -1 && DP[i - 5] != -1)
            DP[i] = min(DP[i - 3], DP[i - 5]) + 1;
        else if (DP[i - 3] != -1)
            DP[i] = DP[i - 3] + 1;
        else if (DP[i - 5] != -1)
            DP[i] = DP[i - 5] + 1;
    }

    cout << DP[N] << endl;

    return 0;
}
