#include<iostream>
#include<math.h>
using namespace std;

int stats[21][21];
bool check[22];
int N;
int ans = 1000000000; // 10억

void DFS(int x, int pos) // x는 카운트 수, pos는 다음 값
{
	if (x == N / 2) // 카운트수가 정원의 1/2이 됐을 때 능력치합 계산
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i] == true && check[j] == true) start += stats[i][j];
				if (check[i] == false && check[j] == false) link += stats[i][j];
			}
		}

		int temp = abs(start - link);
		if (ans > temp) ans = temp;

		return;
	}

	for (int i = pos; i < N; i++)
	{
		check[i] = true;
		DFS(x + 1, i + 1);
		check[i] = false;
	}

}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> stats[i][j];
		}
	}

	DFS(0, 1); // 카운트 0회부터 숫자는 1부터 시작

	cout << ans;
}