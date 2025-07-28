#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    queue<string> q1;
    queue<string> q2;
    
    for(const auto& s : cards1) q1.push(s);
    for(const auto& s : cards2) q2.push(s);

    for(const auto& word : goal)
    {
        if(!q1.empty() && q1.front() == word)
        {
            q1.pop();
        }
        else if(!q2.empty() && q2.front() == word)
        {
            q2.pop();
        }
        else
        {
            return "No";
        }
    }

    return "Yes";
}