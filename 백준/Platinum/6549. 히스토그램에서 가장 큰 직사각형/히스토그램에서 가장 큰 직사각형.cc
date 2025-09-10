#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string line;
		getline(cin, line);

		if (line == "0")
		{
			return 0;
		}

		stringstream ss(line);

		int num_bars; // 첫 번째 숫자를 저장할 변수
		ss >> num_bars; // 첫 번째 숫자만 추출

		vector<int> arr;
		if (num_bars == 0) { // 예외 처리: 0이 들어오면 바로 다음으로
			cout << 0 << "\n";
			continue;
		}

		int height;
		for (int i = 0; i < num_bars; ++i) 
		{
			ss >> height;
			arr.push_back(height);
		}

		arr.push_back(0); 
		long long maxArea = 0;

		stack<pair<int, int>> st;

		for (int i = 0; i < arr.size(); i++)
		{
			int idx = i;
			while (!st.empty() && st.top().first >= arr[i])
			{
				long long height = st.top().first;
				long long startIdx = st.top().second;
				st.pop();

				long long width = i - startIdx;
				maxArea = max(maxArea, height * width);
				idx = startIdx;
			}
			st.push({ arr[i], idx });
		}

		cout << maxArea << "\n";
	}

	return 0;
}