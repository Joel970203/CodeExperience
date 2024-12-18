#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    long long answer = 0;
    int idx = 0;
    
    sort(d.begin(),d.end());
    while(idx < d.size())
    {
        if(answer + d[idx] > budget)
        {
            break;
        }
        
        answer += d[idx];
        idx++;
    }
    return idx;
}