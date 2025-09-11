#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int b, sum = 0;
	cin >> s >> b;
	for (int i=0; i<s.size(); i++) {	// 문자열 크기만큼 반복
		if (s[i] >= '0' && s[i] <= '9') {		// 수가 문자가 아닌 경우
			sum = sum*b + (s[i] - 48);		// 문자 0 의 아스키코드 : 48
		}
		else 
			sum = sum*b + (s[i] - 65 + 10);		// 문자 A 의 아스키코드 : 65
	}
	cout << sum;
		return 0;
}