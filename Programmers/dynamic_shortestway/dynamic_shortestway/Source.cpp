#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int, int>> st;
bool visit[100][100];
bool map[100][100];
int width;
int height;
int answer;

int order[4][2] =
{ { 0,1 },
{1,0},
{-1,0},
{0,-1} };

void find(const int row, const int col, const int pre_row, const int pre_col)
{
	if (row == height && col == width )
	{
		answer++;
		return;
	}
	else if (row == height+1 || col == width+1 || row == 0 || col == 0)
		return;
	//else if (visit[row][col])
	//	return;
	else if (map[row][col])
		return;

	//visit[row][col] = true;
	st.push(make_pair(row, col));

	for (int i = 0; i < 4; i++)
	{
		const int next_row = row + order[i][0];
		const int next_col = col + order[i][1];
		if (pre_row == next_row && pre_col == next_col)
			continue;

		find(next_row, next_col, row,col );
	}

}

int solution(int m, int n, vector<vector<int>> puddles) {
	answer = 0;
	height = n;
	width = m;
	
	memset(&map, 0, width*height);
	memset(&visit, 0, width*height);
	

	for (int i=0 ; i < puddles.size() ; i++)
	{
		for (int l = 0; l < puddles.at(i).size(); l++)
			map[i][l] = true;
	}

	find(1,1,-1,-1);

	return answer;
}

int main()
{
	vector<vector<int>> v;
	for (int i = 0; i < 2; i++)
		v.push_back(vector<int>());

	v[1].push_back(2);
	solution(4, 3, v);
}