#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

int memo[2000][2000];
int cards;
int recursive(const vector<int>& left, const vector<int>& right, int l, int r)
{
	if(l>=cards || r>=cards)
		return memo[l][r];
	
	auto &m = memo[l][r];
	if (m)
		return m;

	if (left[l] > right[r])
	{
		memo[l][r+1] = right[r] + recursive(left, right, l,r+1);
	}
	else
	{
	}

	return res;
}

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	memset(memo, 0, sizeof(int) * 2000 * 2000);
	deque<int> l(left.begin(), left.end());
	deque<int> r(right.begin(), right.end());
	

	return recursive(l, r, 0);
}

int main()
{
	vector<int> left;
	left.push_back(3);
	left.push_back(2);
	left.push_back(5);
	vector<int> right;
	right.push_back(2);
	right.push_back(4);
	right.push_back(1);
	solution(left, right);

}