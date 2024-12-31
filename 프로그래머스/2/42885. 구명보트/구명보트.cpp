#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int low = 0;                 
    int high = people.size() - 1; 

    while (low <= high) {
        if (people[low] + people[high] <= limit) {
            low++;
        }
        high--;
        answer++;
    }

    return answer;
}
