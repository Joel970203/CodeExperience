#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int N, int number) 
{
    vector<unordered_set<int>> dp(9);
    
    if(N==number) return 1;
    int NN = 0;
    for(int i=1;i<=8;++i)
    {
        NN = NN * 10 + N;
        dp[i].insert(NN);
        
        for(int j=1;j<i;j++)
        {
            for(auto a : dp[j])
            {
                for(auto b: dp[i-j])
                {
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b!=0) dp[i].insert(a/b);
                }
            }
        }
        if (dp[i].count(number)) return i;
    }
    return -1;
}