#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) 
{
    vector<pair<int, int>> linked(n);  // prev, next
    stack<pair<int, pair<int, int>>> removed;  // index, (prev, next)
    vector<bool> alive(n, true); 

    for (int i = 0; i < n; ++i) 
    {
        linked[i] = {i - 1, i + 1};
    }

    for (const string& c : cmd) 
    {
        char key = c[0];

        if (key == 'U') {
            int x = stoi(c.substr(2));
            while (x--) k = linked[k].first;
        }
        else if (key == 'D') {
            int x = stoi(c.substr(2));
            while (x--) k = linked[k].second;
        }
        else if (key == 'C') {
            alive[k] = false;
            removed.push({k, linked[k]});
            int prev = linked[k].first;
            int next = linked[k].second;

            if (prev != -1) linked[prev].second = next;
            if (next != n) linked[next].first = prev;

            k = (next == n) ? prev : next;
        }
        else if (key == 'Z') {
            auto [idx, link] = removed.top(); removed.pop();
            alive[idx] = true;
            int prev = link.first;
            int next = link.second;

            if (prev != -1) linked[prev].second = idx;
            if (next != n) linked[next].first = idx;
            linked[idx] = link;
        }
    }

    string result(n, 'O');
    for (int i = 0; i < n; ++i) {
        if (!alive[i]) result[i] = 'X';
    }

    return result;
}
