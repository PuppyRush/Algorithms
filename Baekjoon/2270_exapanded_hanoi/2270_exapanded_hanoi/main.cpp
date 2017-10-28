#define _CRT_SECURE_NO_WARNINGS

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
typedef std::pair<int, int> PINT;
typedef long long LL;



const int stickCount = 3;
vector<std::stack<int>> HANOI(stickCount);
bool isEnd = false;

inline bool move(int to, int from, vector<std::stack<int>> &hanoi) {
	if (!(to >= 0 && to < stickCount) || !(from >= 0 && from < stickCount))
		return false;
	if (hanoi[from].empty())
		return false;
	if ( !hanoi[to].empty() && hanoi[from].top() > hanoi[to].top())
		return false;	
	int temp = hanoi[from].top();
	hanoi[from].pop();
	hanoi[to].push(temp);
	return true;
}

inline PINT min(const PINT &l, const PINT &r)  {
	return l.second < r.second ? l : r;
}

const PINT FAIL = PINT(-1, 123456789);

PINT solve(int now, C_INT pre, C_INT prepre, C_INT diskCount, C_INT moveCount, vector<std::stack<int>> hanoi) {

	if (prepre == now)
		return FAIL;
	if (now == -1)
		now = stickCount - 1;
	else if (now == stickCount)
		now = 0;
	if (!move(now, pre, hanoi))
		return FAIL;

	auto it = find_if(hanoi.begin(), hanoi.end(), [&](const SINT l)->bool {return l.size() == diskCount ? true : false; });
	if (it != hanoi.end()) {
		return PINT(std::distance(hanoi.begin(), it)+1, moveCount);
	}

	PINT p(now, moveCount);
	p = min(solve(now + 1, now, pre, diskCount, moveCount + 1,hanoi), p);
	p = min(solve(now -1 , now, pre, diskCount, moveCount + 1,hanoi), p);

	return p;
}

int main() {
	
	int size = 0;
	vector<int> count(stickCount, 0);

	scanf_s("%d %d %d", &count[0], &count[1], &count[2]);

	for (int l = 0; l < stickCount; l++) {
		for (int i = 0; i < count[l]; i++) {
			int temp;
			scanf_s("%d", &temp);
			HANOI[l].push(temp);
		}
	}

	PINT p(0, 123456789);
	for (int i = 0; i < stickCount; i++) {
		p = min(solve(i, 0,-1, size, 123456789,HANOI), p);
	}
	cout << p.first << endl << p.second;
}