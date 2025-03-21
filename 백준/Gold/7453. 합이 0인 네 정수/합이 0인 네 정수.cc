#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
    fastio();

    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<int> AB, CD;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end(), greater<int>()); // 내림차순

    long long ans = 0;
    int pa = 0, pc = 0;

    while (pa < AB.size() && pc < CD.size())
    {
        int sum = AB[pa] + CD[pc];

        if (sum == 0)
        {
            int abVal = AB[pa];
            int abCount = 0;
            while (pa < AB.size() && AB[pa] == abVal)
            {
                pa++;
                abCount++;
            }

            int cdVal = CD[pc];
            int cdCount = 0;
            while (pc < CD.size() && CD[pc] == cdVal)
            {
                pc++;
                cdCount++;
            }

            ans += (long long)abCount * cdCount;
        }
        else if (sum < 0)
        {
            pa++;
        }
        else
        {
            pc++;
        }
    }

    cout << ans << '\n';
    return 0;
}
