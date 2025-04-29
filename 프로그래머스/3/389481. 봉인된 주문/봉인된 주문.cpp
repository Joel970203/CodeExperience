#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long calculate(string s) 
{
    long long len = s.length();
    long long sum = 0;
    char c;
    for (long long i = 0; i < len; i++) 
    {
        c = s[len - 1 - i];
        sum += (c - 'a' + 1) * pow(26, i);
    }
    
    return sum;
}

string make(long long n) 
{
    vector<char> v;
    
    while (n > 0) 
    {
        n--;
        v.push_back(n % 26 + 'a');
        n /= 26;
    }
    
    string res = "";
    for (long long i = v.size() - 1; i >= 0; i--) 
    {
        res += v[i];
    }
    
    return res;
}

string solution(long long n, vector<string> bans) 
{
    vector<long long> nums;
    for (long long i = 0; i < bans.size(); i++) 
    {
        nums.push_back(calculate(bans[i]));
    }
    
    sort(nums.begin(), nums.end());
    
    for (long long i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= n) 
        {
            n++;
        }
        
        else 
        {
            break;
        }
    }
        
    string answer = make(n);
    return answer;
}
