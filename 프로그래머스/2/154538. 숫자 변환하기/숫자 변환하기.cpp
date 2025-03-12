#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int x, int y, int n) 
{
    if (x == y) return 0; 

    queue<pair<int, int>> q; 
    unordered_set<int> visited; 

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) 
    {
        int current = q.front().first;
        int count = q.front().second;
        q.pop();

        vector<int> next_values = {current + n, current * 2, current * 3};
        for (int next : next_values)
        {
            if (next == y) return count + 1; 
            if (next > y || visited.count(next)) continue; 

            q.push({next, count + 1});
            visited.insert(next);
        }
    }

    return -1; 
}
