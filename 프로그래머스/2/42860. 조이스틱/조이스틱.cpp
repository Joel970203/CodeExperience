#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;

    for (int i=0; i<name.size(); i++) 
    {
        int diff = name[i] - 'A';
        answer += min(diff, 26 - diff);
    }

    int move = name.size() - 1;
    for (int i=0; i<name.size(); i++) 
    {
        int next = i + 1;
        while (next < name.size() && name[next] == 'A') next++;
        move = min(move, i + (int)name.size() - next + min(i, (int)name.size() - next));
    }
    answer += move;

    return answer;
}
