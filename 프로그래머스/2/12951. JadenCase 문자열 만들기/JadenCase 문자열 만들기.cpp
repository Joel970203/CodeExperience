#include <string>
#include <cctype>  
using namespace std;

string solution(string s) 
{
    bool isFirst = true;
    for(int i = 0; i < s.length(); i++)
    {
        
        if(!isFirst)
        {
            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
                
            }
            
        }
        
        if(isFirst)
        {
            if(islower(s[i]))
            {
                s[i] = toupper(s[i]);
                
            }
            
            isFirst = false;
        }
        
        

        
        if(s[i] == ' ')
        {
            isFirst = true;
        }
    }
    return s;
}
