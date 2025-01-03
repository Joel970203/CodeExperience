#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // 1. 전화번호부를 사전순으로 정렬
    sort(phone_book.begin(), phone_book.end());
    
    // 2. 인접한 두 전화번호를 비교하여 접두어 관계인지 확인
    for (int i = 0; i < phone_book.size() - 1; i++) {
        // 만약 현재 번호가 다음 번호의 접두어라면 false 반환
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            return false;
        }
    }
    
    // 접두어 관계가 없으면 true 반환
    return true;
}
