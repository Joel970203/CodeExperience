#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    if (cacheSize == 0) return cities.size() * 5;

    int time = 0;
    deque<string> cache;

    for (auto &city : cities) 
    {
        for (auto &ch : city) ch = tolower(ch);

        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) 
        {
            time += 1;
            cache.erase(it);            // 원래 위치 제거
            cache.push_back(city);      // 가장 최근(back)에 삽입
        } 
        else 
        {
            time += 5;
            if ((int)cache.size() == cacheSize) 
            {
                cache.pop_front();      
            }
            cache.push_back(city);
        }
    }
    return time;
}
