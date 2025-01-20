#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    string k = to_string(n);
    int total = 0;
    for(int i=0;i<k.length();i++)
    {
        int su = k[i] - '0';
        total += su;
    }

    return total;
}