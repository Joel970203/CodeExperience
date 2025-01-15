#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
int min_cost, max_cost;
typedef struct st {
	int x;
	int y;
	int cost; // 0 - 오르막길/ 1 - 내리막길
}st;
vector<st> stair;
int connect[1001];

bool cmp(st a, st b) {
	if (a.cost < b.cost) return true;
	return false;
}
bool cmp2(st a, st b) {
	if (a.cost > b.cost) return true;
	return false;
}

int Find(int x) {
	if (connect[x] == x) return x;
	else return connect[x] =  Find(connect[x]);
}

void Union(int x, int y) {
	int xx = Find(x);
	int yy = Find(y);
	connect[xx] = yy;
}

void low_cost() {
	for (int i = 0; i <= N; i++) connect[i] = i;
	for (int i = 0; i < stair.size(); i++) {
		int x = Find(stair[i].x);
		int y = Find(stair[i].y);
		if (x != y) {
			Union(x, y);
			if (stair[i].cost == 0) min_cost++;
		}
	}
}

void high_cost() {
	sort(stair.begin(), stair.end(), cmp);
	for (int i = 0; i <= N; i++) connect[i] = i;
	for (int i = 0; i < stair.size(); i++) {
		int x = Find(stair[i].x);
		int y = Find(stair[i].y);
		if (x != y) {
			Union(x, y);
			if (stair[i].cost == 0) max_cost++;
		}
	}
}

void solve() {
	low_cost();
	high_cost();
	cout << (max_cost * max_cost) - (min_cost * min_cost);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i <= M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		stair.push_back({ x,y,cost });
	}
	sort(stair.begin(), stair.end(), cmp2);
	solve();
	return 0;
}