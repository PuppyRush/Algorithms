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

typedef std::pair<int, int> PINT;
typedef std::vector<VINT> V2INT;
typedef const std::vector<VINT> C_V2INT;
typedef std::vector<int> C_VINT;
typedef std::vector<int> VINT;
typedef std::vector<string> VSTR;

using namespace std;

inline bool compare(C_VINT &a, C_VINT &b) {

	C_INT size = a.size();
	int i = 0;
	FOR(i, size) {
		if (a[i] != b[i])
			return false;
	}
	return true;

}

void solve(VINT &src) {

	VINT solver = src;
	sort(solver.begin(), solver.end());

	int order = 0;
	queue<int> q;
	map<int,VINT> edge;
	map<int, V2INT> graph;
	map<int, int> cost;
	edge[order++] = src;
	
	while (!q.empty()) {
		
		int ord = q.front();q.pop();

		VINT str = edge[ord];
		V2INT *now;
		if (edge.find(ord) != edge.end()) {
			now = new V2INT();
			graph[ord] = *now;
		}
		else
			now = &graph[ord];
		ord++;

		for (int i = 2; i <= src.size(); i++) {
			for (int l = 0; l < src.size() - i; l++) {
				VINT dest = str;
				reverse(dest.begin() + l, dest.begin() + i - 1);
				if (compare(dest, solver)) {

				}
				if(dest)
				edge[order] = dest;
				now->push_back(dest);
				q.push(order);
			}
			order++;
		}
	}
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
			scanf("%d ", src[l]);
		}
			


	}

	return 0;
}

