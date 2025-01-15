#include <iostream>
#include <vector>
#include <algorithm> // for min function

using namespace std;

char chess[51][51];
int answer = 987654321;

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> chess[i][j];
        }
    }

    for (int q = 0; q + 7 < N; q++)
    {
        for (int p = 0; p + 7 < M; p++)
        {
            int cnt1 = 0;
            int cnt2 = 0;
            // Count mismatches for two possible colorings
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((i + j) % 2 == 0)
                    {
                        if (chess[q + i][p + j] != 'B') cnt1++;
                        if (chess[q + i][p + j] != 'W') cnt2++;
                    }
                    else
                    {
                        if (chess[q + i][p + j] != 'W') cnt1++;
                        if (chess[q + i][p + j] != 'B') cnt2++;
                    }
                }
            }
            answer = min(answer, min(cnt1, cnt2));
        }
    }

    cout << answer << endl;
    return 0;
}