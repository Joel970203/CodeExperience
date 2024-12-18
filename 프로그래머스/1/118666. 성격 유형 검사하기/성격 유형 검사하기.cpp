#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> scores = {
        {'R', 0}, {'T', 0},
        {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0},
        {'A', 0}, {'N', 0}
    };

    for (size_t i = 0; i < survey.size(); i++) 
    {
        string types = survey[i]; 
        char disagree = types[0]; 
        char agree = types[1];    
        int choice = choices[i];  

        if (choice < 4) 
        { 
            scores[disagree] += 4 - choice;
        } else if (choice > 4) 
        { 
            scores[agree] += choice - 4;
        }
    }

    string result = "";

    if (scores['R'] >= scores['T']) 
        result += 'R';
    else 
        result += 'T';

    if (scores['C'] >= scores['F']) 
        result += 'C';
    else 
        result += 'F';

    if (scores['J'] >= scores['M']) 
        result += 'J';
    else 
        result += 'M';

    if (scores['A'] >= scores['N'])
        result += 'A';
    else 
        result += 'N';

    return result;
}
