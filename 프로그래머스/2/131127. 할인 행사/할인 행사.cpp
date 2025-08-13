#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string,int> cloneMap(const unordered_map<string,int>& src)
{
    return src; 
}

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    unordered_map<string,int> need;
    for (size_t i = 0; i < want.size(); ++i)
        need[want[i]] = number[i];

    if (discount.size() < 10) return 0;

    int answer = 0;

    for (size_t i = 0; i + 9 < discount.size(); ++i)
    {
        bool buy = true; 
        auto cur = cloneMap(need); 

        for (size_t j = i; j <= i + 9; ++j) 
        {
            if (cur.count(discount[j]))  
                --cur[discount[j]];
        }

        for (const auto& p : cur) 
        {
            if (p.second > 0) 
            { 
                buy = false;
                break;
            }
        }

        if (buy) ++answer;
    }
    return answer;
}
