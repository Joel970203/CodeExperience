#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    unordered_map<int,string> days;
    days[0] = "FRI";;
    days[1] = "SAT";
    days[2] = "SUN";
    days[3] = "MON";
    days[4] = "TUE";
    days[5] = "WED";
    days[6] = "THU";
    vector<int> month = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    int mont = a - 1;
    int dayt = b - 1;

    for(int i = 0; i<mont ;i++)
    {
        dayt += month[i];
    }
    
    int k = (dayt % 7);
    answer = days[k]; 
    
    return answer;
}