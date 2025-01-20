#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n) {
    int answer = 0;
    set<int> factors;  // 중복을 피하기 위해 set 사용
    
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            factors.insert(i);  
            factors.insert(n / i);  
        }
    }
    
    for(int factor : factors) {
        answer += factor;
    }
    
    return answer;
}
