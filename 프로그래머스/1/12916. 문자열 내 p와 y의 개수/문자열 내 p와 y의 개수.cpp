#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int yCnt = 0, pCnt = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P')  
        {
            pCnt++;
        }
        
        else if(s[i] == 'y' || s[i] == 'Y')
        {
            yCnt++;
        }
    }
    
    return (yCnt == pCnt);  
}
