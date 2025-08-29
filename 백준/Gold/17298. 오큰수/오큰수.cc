#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	stack<pair<int,int>> st;
	vector<int> NGE(N,-1);
	for (int i = 0; i < N; i++)
	{
		if (st.empty())
		{
			st.push({arr[i], i});
		}

		else
		{  
			while (!st.empty() && arr[i] > st.top().first)
			{
				NGE[st.top().second] = arr[i];
				st.pop();
			}

			st.push({ arr[i],i });
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << NGE[i] << " ";
	}

	return 0;
}