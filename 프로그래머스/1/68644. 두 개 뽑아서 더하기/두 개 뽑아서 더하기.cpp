#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> temp;
    for(int i=0;i<numbers.size();i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            int ans = numbers[i]+numbers[j];
            temp.insert(ans);
        }
    }
    
    for(auto cur : temp)
    {
        answer.push_back(cur);
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}