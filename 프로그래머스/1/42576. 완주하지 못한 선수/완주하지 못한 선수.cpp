#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer;
    unordered_map<string,int> umap;
    for(const auto &cur : participant)
    {
        umap[cur]++;
    }
    
    for(const auto &cur : completion)
    {
        umap[cur]--;
    }
    
    for(const auto &cur :umap)
    {
        if(cur.second == 1)
        {
            return cur.first;
        }
    }
    
    
}