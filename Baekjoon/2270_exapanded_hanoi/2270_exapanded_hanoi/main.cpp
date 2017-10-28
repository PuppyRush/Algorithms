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
vector<std::stack<int>> hanoi(stickCount);
bool isEnd = false;

inline bool move(int to, int from) {
	if (hanoi[from].empty())
		return false;
	if (hanoi[from].top() > hanoi[to].top())
		return false;	
	int temp = hanoi[from].top();
	hanoi[from].pop();
	hanoi[to].push(temp);
	return true;
}

inline PINT min(PINT l, PINT r)  {
	return l.second < r.second ? l : r;
}



PINT solve(C_INT now, C_INT pre, C_INT prepre, C_INT diskCount, C_INT moveCount) {

	if (now == pre)
		return PINT(-1, 123456789);
	if (now == -1)
		return PINT(-1, 123456789);
	if (now == stickCount)
		return PINT(-1, 123456789);
	if (prepre == now)
		return PINT(-1, 123456789);

	auto it = find_if(hanoi.begin(), hanoi.end(), [&](const SINT l)->bool {return l.size() == diskCount ? true : false; });
	if (it != hanoi.end()) {
		return PINT(std::distance(hanoi.begin(), it)+1, moveCount);
	}

	PINT p(now, moveCount);
	bool b;
	if(now != stickCount-1)
		b = move(now, now + 1);
	p = min(solve(now + 1, now, pre, diskCount, moveCount + 1), p);
	if (b)
		move(now + 1, now);

	if (now != 0)
		b = move(now, now -1);
	p = min(solve(now -1 , now, pre, diskCount, moveCount + 1), p);
	if (b)
		move(now - 1, now);

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
			hanoi[l].push(temp);
		}
	}

	PINT p(0, 123456789);
	for (int i = 0; i < stickCount; i++) {
		p = min(solve(i, -1,-1, size, 123456789), p);
	}
	cout << p.first << endl << p.second;
}