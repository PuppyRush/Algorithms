

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <set>
#include <queue>

using namespace std;

typedef const int C_INT;
typedef const unsigned int C_UINT;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef std::vector<std::stack<int>> S2INT;
typedef std::stack<int> SINT;
typedef std::stack<char> SCHAR;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;
typedef long long LL;

using namespace std;


int reductionCost(vector <int> num) {

	int val = 0;
	auto comp = [](const int &a, const int &b) -> bool { return a > b; };
	auto pq = std::priority_queue<int, std::vector<int>, decltype(comp)>(comp);

	int count = num[0];
	for (int i = 1; i <=count; i++) {
		pq.push(num[i]);
	}

	while (!pq.empty()) {

		int l = pq.top();
		pq.pop();
		int r = pq.top();
		pq.pop();
		int sums = l + r;
		val += sums;
		pq.push(sums);
	}
	return val;
}

int main() {

	VINT v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	reductionCost(v);


}


typedef std::multiset<int>::iterator setIt;
long maxPoints(vector <int> elements) {
	auto comp = [](const int &a, const int &b) -> bool { return a > b; };
	multiset<int, comp> sets;
	for (auto it = elements.begin(); it != elements.end(); it++) {
		sets.insert(*it);
	}

	long sums = 0;
	for (!sets.empty()) {
		//std::pair<setIt,setIt> ret = mymultiset.equal_range(sets.begin());
		const auto val = *sets.begin();
		sums += val;
		if (sets.count(val)>0) {
			sets.erase(val);
		}
		sets.erase(sets.begin());
	}


}
