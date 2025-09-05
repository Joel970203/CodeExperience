#include <iostream>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

long long answer = 0;

void mergeSort(vector<int>& arr, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	vector<int> temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp.push_back(arr[i++]);
		}

		// 7 5 3 
		else
		{
			temp.push_back(arr[j++]);
			answer += (mid - i + 1);
		}
	}

	while (i <= mid) temp.push_back(arr[i++]);
	while (j <= right) temp.push_back(arr[j++]);

	for (int k = left; k <= right; k++)
	{
		arr[k] = temp[k - left];
	}

}

int main()
{
	fastio();
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	mergeSort(arr, 0, N - 1);
	cout << answer << endl;
}