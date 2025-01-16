#include <string>
using namespace std;

string solution(int n) 
{
    string answer = "";
    string num = "124"; 

    while (n > 0) {
        int remainder = (n - 1) % 3; // 42
        answer = num[remainder] + answer; 
        n = (n - 1) / 3; 
    }

    return answer;
}
