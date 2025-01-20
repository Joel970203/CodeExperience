#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ans;
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            ans.push_back(arr[i]);  
        }
    }
    
    return ans;
}