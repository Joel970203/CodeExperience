#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxDiff = 0;
vector<int> bestShot;

void dfs(int idx, int remain, vector<int>& ryan, const vector<int>& apeach) 
{
    if (idx == 11) 
    {
        if (remain > 0)
            ryan[10] += remain; 

        int ryanScore = 0, apeachScore = 0;

        for (int i = 0; i < 11; i++) 
        {
            if (ryan[i] == 0 && apeach[i] == 0)
                continue;

            if (ryan[i] > apeach[i])
                ryanScore += 10 - i;
            else
                apeachScore += 10 - i;
        }

        if (ryanScore > apeachScore) 
        {
            int diff = ryanScore - apeachScore;

            if (diff > maxDiff) 
            {
                maxDiff = diff;
                bestShot = ryan;
            }
            else if (diff == maxDiff) 
            {
                for (int i = 10; i >= 0; i--) 
                {
                    if (ryan[i] > bestShot[i])
                    {
                        bestShot = ryan;
                        break;
                    }
                    else if (ryan[i] < bestShot[i]) 
                    {
                        break;
                    }
                }
            }
        }

        if (remain > 0)
            ryan[10] -= remain; 

        return;
    }

    if (remain > apeach[idx])
    {
        ryan[idx] = apeach[idx] + 1;
        dfs(idx + 1, remain - ryan[idx], ryan, apeach);
        ryan[idx] = 0; 
    }
    dfs(idx + 1, remain, ryan, apeach);
}


vector<int> solution(int n, vector<int> info)
{
    vector<int> ryan(11, 0);
    dfs(0, n, ryan, info);

    if (bestShot.empty())
        return {-1};
    return bestShot;
}
