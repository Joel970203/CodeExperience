#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        int n = storey % 10; // 1의 자리의 수
        storey /= 10;        // 자리수 오른쪽으로 1칸씩 이동
        
        // 1) 1의 자리수가 5미만일 때, 
        // n만큼 버튼 누르기
        if(n < 5)
        {
            answer += n;
        }
        
        // 2) 1의 자리수가 5초과일 때, 
        // 한 자리 수 위 버튼 1번 누르고 10-n만큼 버튼 누르기 
        else if(n > 5)
        {
            answer += (10 - n);  // n을 10으로 만들기 위해 필요한 버튼 수
            ++storey;  // 자릿수를 올림
        }
        
        // 3) 1의 자리수가 5일 때,
        // 다음 자리수가 5이상이면 자리를 올리고, 5미만이면 내림
        else
        {
            int test = storey % 10;    
            if(test >= 5)  // 앞 자리가 5 이상이면 올림
            {
                ++storey;
            }
            answer += n;  // 5일 경우에는 +5 버튼을 눌러야 함
        }
        
    }
    
    return answer;
}
