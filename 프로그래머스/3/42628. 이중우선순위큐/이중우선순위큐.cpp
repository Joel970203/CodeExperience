#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations)
{
    multiset<int> ms;
    
    for (const string& op : operations)
    {
        char command = op[0]; 
        int value = stoi(op.substr(2));  
        
        if (command == 'I') 
        {
            ms.insert(value);
        } 
        else if (command == 'D') 
        {
            if (!ms.empty()) {
                if (value == 1) 
                {
                    ms.erase(prev(ms.end()));  
                } else if (value == -1) 
                {
                    ms.erase(ms.begin());  
                }
            }
        }
    }

    vector<int> answer;
    if (!ms.empty()) 
    {
        answer.push_back(*prev(ms.end()));  
        answer.push_back(*ms.begin());  
    } else 
    {
        answer = {0, 0};  
    }

    return answer;
}
