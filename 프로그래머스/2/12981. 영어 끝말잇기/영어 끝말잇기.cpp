#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    unordered_map<string,int> umap;
    int turn = 0;
    int round = 1;
    char temp = '0';
    
    for(auto &cur : words)
    {
        turn++;
        if(turn > n)
        {
            turn = turn%n;
            round++;
        }
        
        if(temp == '0') // 맨처음
        {
            temp = cur[cur.length()-1];
            umap[cur]++;
        }
        
        else // 맨처음 아닐때 
        {
            if(cur[0] == temp)
            {
                temp = cur[cur.length()-1];
                if(umap[cur] == 0)
                {
                    umap[cur]++;
                }
                else
                {
                    answer.push_back(turn);
                    answer.push_back(round);

                    return answer;
                }
            }
            
            else
            {
                answer.push_back(turn);
                answer.push_back(round);
                return answer;
            }
        }

    }
    
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
    
}