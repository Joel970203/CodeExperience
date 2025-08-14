#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

bool orderingGenre(const pair<string,int> &a, const pair<string,int> &b)
{
    return a.second > b.second;
}

bool orderingSong(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
        
    /*
    장르, 플레이 횟수로 어떤 장르를 뽑을지부터 선택하고
    장르, 플레이횟수,고유넘버로 장르, 어떤 곡을 선택할지 결정 
    */
    
    vector<int> answer;
    unordered_map<string,int> genreMap;
    unordered_map<string,vector<pair<int,int>>> songMap;
    
    
    for(int i=0; i<genres.size();i++)
    {
        string genre_name = genres[i];
        int genre_play = plays[i];
        genreMap[genre_name] += genre_play;
        songMap[genre_name].push_back({genre_play,i});
    }
    
    vector<pair<string,int>> ordered_genreMap(genreMap.begin(),genreMap.end());
    sort(ordered_genreMap.begin(),ordered_genreMap.end(),orderingGenre);
    
    
    /*
    pop 3100 classic 1450
    classic, [500 150 800] , pop [600 , 2500]
    */
    for(const auto& cur : ordered_genreMap)
    {
        auto &temp = songMap[cur.first];
        sort(temp.begin(),temp.end(),orderingSong);
        
        for(int i=0;i<min(2,(int)temp.size());++i)
        {
            answer.push_back(temp[i].second);
        }
    }
    
    return answer;
}