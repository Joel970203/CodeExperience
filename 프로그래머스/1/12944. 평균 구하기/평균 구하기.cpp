#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {

    double total = 0;
    for(int i=0;i<arr.size();i++)
    {
        total += arr[i];        
    }
    double answer = total / arr.size();
    return answer;
}