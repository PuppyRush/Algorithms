#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <set>
using namespace std;

int total = 0;
int len;
std::set<pair<int, int>> rec;
bool maps[10][10];
bool visit[10][10];
int order[4][2] =
{ {1,0},
{0,1},
{-1,0},
{0,-1} };

int solve(int row, int col, int count)
{
	if (row == -1 || col == -1 || row == len || col == len)
		return count;
	else if (!maps[row][col])
		return count;

	count++;

	if (rec.count(make_pair(row, col)))
		rec.erase(make_pair(row, col));

	maps[row][col] = false;

	for (int i = 0; i < 4; i++)
	{
		count = solve(row + order[i][0], col + order[i][1], count);
	}

	return count;
}


int main() {

	int N;
	scanf("%d", &N);
	len = N;
	memset(&maps, 0, N*N);
	memset(&visit, 0, N*N);

	for(int i=0 ; i < N ; i++)
		for (int l = 0; l < N; l++)
		{
			int v;
			scanf("%d", &v);
			maps[i][l] = v;
			if (v)
			{
				rec.insert(make_pair(i, l));
			}
		}

	set<int> ans;
	while (!rec.empty())
	{
		int a = 0;
		if ((a = solve(rec.begin()->first, rec.begin()->second,0)) > 0)
			ans.insert(a);
	}

	return 0;
}
//
//6
//0 1 1 0 0 0
//0 1 1 0 1 1
//0 0 0 0 1 1
//0 0 0 0 1 1
//1 1 0 0 1 0
//1 1 1 0 0 0
//출력 1
//3
//4 5 7
//
//보기 입력 2
//4
//0 0 0 0
//0 0 0 0
//0 0 0 0
//0 0 0 0
//출력 2
//0