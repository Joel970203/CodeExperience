#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dy[4] = { -1,0,1,0 }; // 방향을 증가하는 식으로 가자... 상 우 하 좌 
int dx[4] = { 0,1,0,-1 }; 
int N, M;
int minBlind = INT_MAX;



void progressCCTV(vector<vector<int>>& graph, int cctvY, int cctvX, int dir)
{
	int curY = cctvY + dy[dir];
	int curX = cctvX + dx[dir];


	while (true)
	{
		if (curY < 0 || curY >= N || curX < 0 || curX >= M) break;
		if (graph[curY][curX] == 6) break;

		if (graph[curY][curX] >= 1 && graph[curY][curX] <= 5)
		{
			curY += dy[dir];
			curX += dx[dir];
			continue;
		}

		graph[curY][curX] = -1;

		curY += dy[dir];
		curX += dx[dir];
	}


	return;
}

void setDirection(vector<vector<int>> &graph, int cctvY, int cctvX,vector<int> &arr)
{
	// 여기서 어떻게 해줄건지 생각해보자
	// cctv 2번같은경우는 2 3 이 같이 들어온다 
	// 그럼 번호에 따라 보내주면 되겠군. 

	for (int i = 0; i < arr.size(); i++)
	{
		int dir = arr[i];
		progressCCTV(graph, cctvY, cctvX, dir);
	}

	return;
}


// 사각 지대 찾는용도 
int findBlind(const vector<vector<int>>& graph)
{
	int blind = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0) blind++;
		}
	}

	return blind;
}

// 1. 백트래킹 필요하고, 백트래킹에 들어가는 그래프마다 달라야함.
// 2. 백트래킹에 필요한 원소는 인덱스, cctv 좌표값, 그래프 
// 3. 반환 조건은 인덱스가 꽉찼을때. 
// 4. 백트래킹 진행은, cctv 타입을 받고, 방향을 정해서 다음 백트래킹으로 

void backtracking(vector<vector<int>> graph,const vector<pair<int,int>> &coordinate, int idx)
{
	if ((int)coordinate.size() == idx) // 리턴 
	{
		minBlind =  min(minBlind,findBlind(graph));
		return;
	}

	int cctvY = coordinate[idx].first;
	int cctvX = coordinate[idx].second;
	int cctv = graph[cctvY][cctvX];

	// cctv 타입에 따라 결정
	if (cctv == 1)
	{
		// 여기서 어떻게할까 ? 
		// cctv 1은 상 하 좌 우를 그래프를 칠한다음, 다음으로 넘어가야함.
		// 중간 함수가 더 필요하다. 
		for (int i = 0; i < 4; i++)
		{
			vector<vector<int>> newGraph = graph;
			vector<int> dir;
			dir.push_back(i);
			setDirection(newGraph, cctvY, cctvX,dir);
			backtracking(newGraph, coordinate, idx + 1);
		}
	}

	else if (cctv == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			vector<vector<int>> newGraph = graph;
			vector<int> dir;
			dir.push_back(i);
			dir.push_back(i + 2);
			setDirection(newGraph, cctvY, cctvX, dir);
			backtracking(newGraph, coordinate, idx + 1);
		}
	}

	else if (cctv == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<vector<int>> newGraph = graph;
			vector<int> dir;
			dir.push_back(i);
			dir.push_back((i + 1) % 4);
			setDirection(newGraph, cctvY, cctvX, dir);
			backtracking(newGraph, coordinate, idx + 1);
		}
	}


	else if (cctv == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<vector<int>> newGraph = graph;
			vector<int> dir;
			for (int j = 0; j < 4; j++)
			{
				if (j == i) continue; 
				dir.push_back(j);
			}
			setDirection(newGraph, cctvY, cctvX, dir);
			backtracking(newGraph, coordinate, idx + 1);
		}
	}


	else if (cctv == 5)
	{
		vector<vector<int>> newGraph = graph;
		vector<int> dir;
		dir.push_back(0);
		dir.push_back(1);
		dir.push_back(2);
		dir.push_back(3);
		setDirection(newGraph, cctvY, cctvX, dir);
		backtracking(newGraph, coordinate, idx + 1);
	}

	return;
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(M));
	vector<pair<int, int>> coordinate;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int k;
			cin >> k;
			graph[i][j] = k;
			if (k != 0 && k != 6)
			{
				coordinate.push_back({ i,j });
			}
		}
	}

	backtracking(graph,coordinate,0);
	cout << minBlind << endl;
}