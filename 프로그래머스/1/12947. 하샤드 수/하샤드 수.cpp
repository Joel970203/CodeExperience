#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string temp = to_string(x);
    int sum = 0;
    for(int i=0;i<temp.length();i++)
    {
        int su = temp[i] -'0';
        sum += su;
    }
    
    if(x%sum == 0)
    {
        return true;
    }
    
    else
        return false;
}