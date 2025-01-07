#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = want.size();
    int m = discount.size();  

    map<string, int> want_count;
    for (int i = 0; i < n; i++) 
    {
        want_count[want[i]] = number[i];
    }

    for (int i = 0; i <= m - 10; i++) 
    {
        map<string, int> discount_count;
        
        for (int j = i; j < i + 10; j++)
        {
            discount_count[discount[j]]++;
        }
        
        bool valid = true;
        
        for (auto& item : want_count) 
        {
            if (discount_count[item.first] < item.second) 
            {
                valid = false;
                break;
            }
        }
        if (valid) 
        {
            answer++;
        }
    }

    return answer;
}
