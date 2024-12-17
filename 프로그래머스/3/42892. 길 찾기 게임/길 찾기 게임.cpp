#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;


class TREE
{
public:
	int x;
	int y;
	int IDX;
	TREE* Left;
	TREE* Right;

	TREE(int x, int y, int IDX, TREE* Left, TREE* Right)
	{
		this->x = x;
		this->y = y;
		this->IDX = IDX;
		this->Left = Left;
		this->Right = Right;
	}
	
};

bool Cmp(TREE A, TREE B)
{
	if (A.y >= B.y)
	{
		if (A.y == B.y)
		{
			if (A.x < B.x)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void Make_Binary_Tree(TREE* Root, TREE* Child)
{
	if (Root->x > Child->x)
	{
		if (Root->Left == nullptr)
		{
			Root->Left = Child;
			return;
		}
		Make_Binary_Tree(Root->Left, Child);
	}
	else
	{
		if (Root->Right == nullptr)
		{
			Root->Right = Child;
			return;
		}
		Make_Binary_Tree(Root->Right, Child);
	}
}

void PreOrder(TREE* Root, vector<int>& answer)
{
	if (Root == nullptr) return;
	answer.push_back(Root->IDX);
	PreOrder(Root->Left, answer);
	PreOrder(Root->Right, answer);
}

void PostOrder(TREE* Root, vector<int>& answer)
{
	if (Root == nullptr) return;
	PostOrder(Root->Left, answer);
	PostOrder(Root->Right, answer);
	answer.push_back(Root->IDX);

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;
	vector<TREE> tree;

	for (int i = 0; i < nodeinfo.size(); i++)
	{
		int x = nodeinfo[i][0];
		int y = nodeinfo[i][1];
		int Idx = i + 1;
		tree.push_back({ x,y,Idx,nullptr,nullptr });
	}

	sort(tree.begin(), tree.end(), Cmp);
	TREE* Root = &tree[0];
	for (int i = 1; i < tree.size(); i++)
	{
		Make_Binary_Tree(Root, &tree[i]);
	}

	vector<int> Pre;  PreOrder(Root, Pre);
	vector<int> Post; PostOrder(Root, Post);
	answer.push_back(Pre);
	answer.push_back(Post);

	return answer;
}