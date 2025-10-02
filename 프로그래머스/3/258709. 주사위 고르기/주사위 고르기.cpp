#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int max_cnt = INT_MIN;
vector<int> best;
vector<int> CalcSum(const vector<vector<int>> &dice,const vector<int>& arr)
{
    vector<int> sums = {0};
    for(int idx : arr)
    {
        vector<int> next;
        for(int s: sums)
        {
            for(int face : dice[idx])
            {
                next.push_back(s+face);
            }
        }
        sums.swap(next);
    }
    return sums;
}

int CalcWins(vector<int> &A,vector<int> &B)
{
    int sum = 0;
    sort(B.begin(),B.end());
    
    for(int cur : A)
    {
        sum += lower_bound(B.begin(),B.end(),cur) - B.begin();
    }
    
    return sum;
}

void DFS(const vector<vector<int>> &dice,int N,int K,vector<int> &A,vector<bool>& used,int idx)
{
    if(A.size()==K)
    {
        vector<int> B;
        B.reserve(K);
        for(int i=0;i<N;i++)
        {
            if(!used[i]) B.push_back(i); 

        }
        vector<int> ACnt = CalcSum(dice,A);
        vector<int> BCnt = CalcSum(dice,B);
        
        int winCnt = CalcWins(ACnt,BCnt);
        if(winCnt > max_cnt)
        {
            max_cnt = winCnt;
            best = A;
        }
        return;
    }
    
    for(int i=idx; i<N;i++)
    {
        used[i] = true;
        A.push_back(i);
        DFS(dice,N,K,A,used,i+1);
        A.pop_back();
        used[i] = false;
    }
    
    return;
}

vector<int> solution(vector<vector<int>> dice) 
{
    int N = (int)dice.size();
    int K = N / 2;
    vector<int> A;
    vector<bool> used(N,false);
    
    DFS(dice, N, K, A, used, 0);
    
    vector<int> answer = best;
    for (int &x : answer) x++;
    sort(answer.begin(), answer.end());
    
    return answer;
}
