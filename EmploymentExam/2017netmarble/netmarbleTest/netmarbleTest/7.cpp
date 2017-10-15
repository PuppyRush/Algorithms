#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int solution(vector<int> paper)
{
	int answer = -1;

	auto comp = [&](int l, int r) {return l < r ? l : r; };
	sort(paper.begin(), paper.end(),comp);
	vector<int> val;

	int accu = 0;
	for (int i = 0; i < paper.size() || paper[i] != 0; i++) {
		accu += paper[i];
		int l = pow(accu, 2);
		if (l <= accu)
			val.push_back(i+1);

	}
	sort(val.begin(), val.end(), comp);
	return val.back();
}


int solution(vector<vector<int> > seat)
{
	int answer = 0;

	std::set<pair<int, int>> s;
	for (int i = 0; i < seat.size(); i++) {
		int l = seat[i][0];
		int r = seat[i][1];
		auto se = make_pair(l, r);
		if (s.count(se) == 0) {
			answer++;
			s.insert(se);
		}
	}

	return answer;
}