#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    // 빈 병의 개수 n 
    // 콜라를 받기위해 마트에 주어야하는 병수 a
    // 빈 병 a개를 가져다 주면 주는 콜라 병수 b
    int answer = 0;
    
    while(n>=a)
    {
        n -= a;
        answer += b;
        n += b;
    }
    
    return answer;

}