#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    
    int min = 1e9;
    int minIdx;
    for(int i = 0; i <  arr.size(); i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            minIdx = i;
        }
    }
    arr.erase(arr.begin() + minIdx);
    if(arr.empty())
    {
        arr.push_back(-1);
        return arr;
    }
    else 
    {
        return arr;
    }

}