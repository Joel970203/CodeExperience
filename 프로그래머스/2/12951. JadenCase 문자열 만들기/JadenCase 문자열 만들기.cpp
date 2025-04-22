#include <string>
#include <cctype>  
#include <vector>
using namespace std;

string solution(string s) 
{
    vector<int> arr;
    bool trigger = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (isspace(s[i]))
        {
            trigger = true;
            continue;
        }

        if (isupper(s[i]) && trigger == false)
        {
            s[i] = tolower(s[i]); 
        }

        if (trigger || i == 0)
        {
            if (islower(s[i]))
            {
                s[i] = toupper(s[i]);
            }

            trigger = false;
        }
    }
    
    return s;
}
