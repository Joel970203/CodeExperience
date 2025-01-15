#include <iostream>
#include <cmath> //math 클래스 사용

using namespace std;

int main() {
	int num;//참가자 수
	double kim, im;//김지민과 임한수의 번호
	cin >> num >> kim >> im;

	int round = 0;//두사람이 치룬 경기 수

	while (kim != im) {//김지민과 임한수의 번호가 같아질때 까지 반복
		kim = ceil(kim / 2);
		im = ceil(im / 2);
		round++;
	}

	cout << round;

	return 0;
}