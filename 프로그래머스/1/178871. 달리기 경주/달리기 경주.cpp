#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    unordered_map<string, int> rank_map;
    
    for (int i = 0; i < players.size(); ++i) 
    {
        rank_map[players[i]] = i;
    }

    for (const string& calling : callings)
    {
        int current_rank = rank_map[calling];
        if (current_rank == 0) continue; 
        
        int prev_rank = current_rank - 1;
        string prev_player = players[prev_rank];

        swap(players[current_rank], players[prev_rank]);

        rank_map[calling] = prev_rank;
        rank_map[prev_player] = current_rank;
    }

    return players;
}