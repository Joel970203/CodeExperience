#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

// idx: 현재 인덱스, sum: 현재까지 합
void backtrack(int idx, int sum, const vector<int>& arr, int target) {
	if (idx == arr.size()) {
		if (sum == target)
			cnt++;
		return;
	}

	// 현재 원소 포함
	backtrack(idx + 1, sum + arr[idx], arr, target);

	// 현재 원소 미포함
	backtrack(idx + 1, sum, arr, target);
}

int main() {
	int N, S;
	cin >> N >> S;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	backtrack(0, 0, arr, S);

	// 공집합 제외
	if (S == 0) cnt--;

	cout << cnt << '\n';
}
