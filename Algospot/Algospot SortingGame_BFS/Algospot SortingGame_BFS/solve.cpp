#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)
#define FOR_EACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAKE_V2INT(a,b) V2INT(a,VINT(b))


#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

typedef const int* C_INT_P;
typedef const int C_INT;
typedef unsigned int UINT;
typedef const unsigned int C_UINT;
typedef unsigned char UCHAR;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned long long ULL;

typedef const std::vector<int> C_VINT;
typedef std::vector<int> VINT;
typedef std::vector<string> VSTR;
typedef const std::vector<string> C_VSTR;
typedef std::pair<int, int> PINT;
typedef const std::pair<int, int> C_PINT;
typedef std::vector<VINT> V2INT;
typedef const std::vector<VINT> C_V2INT;


using namespace std;


int solve(C_VINT src, const map<VINT, int> *cost) {

	VINT perm(src.size());
	int i = 0, l = 0;
	FOR(i, src.size()) {
		l = 0;
		int smaller = 0;
		FOR(l, src.size()) {
			if (src[l] > src[i])
				smaller++;
		}
		perm[i] = smaller;
	}
	return cost->at(perm);
}

map<VINT,int>* preProcess(C_INT size) {

	VINT solver(size);
	int i = 0;
	FOR(i, size) {
		solver[i] = i;
	}

	//아직 방문하지 않은 정점.
	queue<VINT> q;
	map<VINT, int> *cost = new map<VINT, int>();
	cost->insert(pair<VINT, int>(solver, 0));
	q.push(solver);
	while (!q.empty()) {
		
		VINT comp = q.front(); 
		q.pop();
		int _cost = cost->at(comp);
		for (int i = 0; i < size ; i++) {
			for (int l = i + 2; l <= size - i; l++) {
				VINT dest = comp;
				reverse(dest.begin() + i, dest.begin() + l);
				if (cost->count(dest) == 0) {
					cost->insert(pair<VINT, int>(dest, _cost + 1));
					q.push(dest);
				}
			}
		}
	}
	return cost;
}

int main() {

	int testCase = 0;
	scanf("%d", &testCase);

	int i = 0;
	FOR(i, testCase) {
		
		int count = 0;
		scanf("%d", &count);
		VINT src(count);		
		int l = 0;
		FOR(l, count) {
			scanf("%d", &src[l]);
		}
		auto cost = preProcess(count);
		cout << solve(src,cost) << endl;
	}

	return 0;
}

