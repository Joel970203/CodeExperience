#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    vector<int> cnt(3);
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i] == first[i% first.size()]) cnt[0]++;
        if(answers[i] == second[i% second.size()]) cnt[1]++;
        if(answers[i] == third[i% third.size()]) cnt[2]++;
        
    }
    
    int max_num = *max_element(cnt.begin(),cnt.end());
    
    for(int i=0;i<3;i++)
    {
        if(cnt[i] == max_num)
        {
            answer.push_back(i+1);
        }
    }
    return answer;
}