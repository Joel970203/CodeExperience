#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) 
    {
        int temp;
        cin >> temp;
        // vec이 비어 있거나, 마지막 원소보다 현재 값이 클 경우
        if (vec.empty() || vec.back() < temp) 
        {
            vec.push_back(temp);  // 새로운 값 추가
        }
        else 
        {
            // lower_bound로 적절한 위치를 찾아서 값을 갱신
            *lower_bound(vec.begin(), vec.end(), temp) = temp;
        }
    }
    cout << vec.size() << endl;  // LIS의 길이 출력
    return 0;
}
