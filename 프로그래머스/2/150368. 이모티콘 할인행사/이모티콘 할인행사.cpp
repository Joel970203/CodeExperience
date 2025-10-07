#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int discount[4] = {10, 20, 30, 40};

pair<int,int> answer = {-1, -1};

void Calc(const vector<vector<int>> &users, const vector<int> &emoticons, const vector<int> &arr)
{
    int registered = 0;
    int total = 0;

    vector<int> price;
    for (int i = 0; i < arr.size(); i++) {
        price.push_back(emoticons[i] * (100 - arr[i]) / 100);
    }

    for (int i = 0; i < users.size(); i++) {
        int minDiscount = users[i][0];
        int maxSpend = users[i][1];    
        int sum = 0;

        for (int j = 0; j < emoticons.size(); j++) {
            if (arr[j] >= minDiscount)
                sum += price[j];
        }

        if (sum >= maxSpend)
            registered++;
        else
            total += sum; 
    }

    if (registered > answer.first ||
       (registered == answer.first && total > answer.second)) {
        answer = {registered, total};
    }
}

void backTracking(const vector<vector<int>> &users, const vector<int> &emoticons, int depth, vector<int> &arr)
{
    if (depth == emoticons.size()) {
        Calc(users, emoticons, arr);
        return;
    }

    for (int i = 0; i < 4; i++) {
        arr.push_back(discount[i]);
        backTracking(users, emoticons, depth + 1, arr);
        arr.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    vector<int> arr;
    backTracking(users, emoticons, 0, arr);
    return {answer.first, answer.second};
}
