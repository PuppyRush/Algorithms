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
typedef std::vector<std::vector<int>> V2INT;
typedef const std::vector<std::vector<int>> C_V2INT;
typedef std::vector<int> VINT;
typedef std::vector<string> VSTR;

using namespace std;

struct SSC{
		
private:

	V2INT adj;
	VINT sccId;

	VINT discovered, finished;
	stack<int> st;

	int sccCounter, vertexCounter;

	int scc(int here) {
		int ret = discovered[here] = vertexCounter++;
		
		st.push(here);
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
		
			if (discovered[there] == -1)
				ret = min(ret, scc(there));
		
			else if (discovered[there] < discovered[here] && finished[there] != 1)
				ret = min(ret, discovered[there]);
		}
		
		if (ret == discovered[here]) {
		
			while (true) {
				int t = st.top();
				st.pop();
				sccId[t] = sccCounter;
				if (t == here) break;
			}
			++sccCounter;
		}
		finished[here] = 1;
		return ret;
	}

public:
	
	SSC(C_V2INT &src) {
		adj = src;
		sccId = discovered = VINT(adj.size(), -1);
		finished = VINT(adj.size(), 0);
		sccCounter = vertexCounter = 0;
	}

	VINT tarjanSCC() {	
		for (int i = 0; i < adj.size(); i++) 
			if (discovered[i] == -1) scc(i);
		return sccId;
	}

};

int solve(VINT &ssc, V2INT &src) {

	int l = 0;
	FOR(l, ssc.size()-1) {
		if (ssc[l] == ssc[l + 1]) {
			return 0;
		}
	}
	return 1;
}


int main() {

	//int caseSize = 0;
	//scanf("%d", &caseSize);

	//int i = 0;
	//FOR(i, caseSize) {
		int edgeCount, clauseCount;
		scanf("%d %d", &edgeCount, &clauseCount);

		auto src = MAKE_V2INT(edgeCount*2, 0);

		int l = 0;
		FOR(l, clauseCount) {
			int e[2];
			int t = 0;
			FOR(t, 2) {
				scanf("%d", &e[t]);
				if (e[t] < 0) {
					e[t] = (-e[t]) * 2-1;
				}
				else
					e[t] = 2 * e[t] - 2;
			}
			src[e[0]].push_back(e[1]);
		}
		
		SSC tarjan(src);
		auto ssc = tarjan.tarjanSCC();
		reverse(ssc.begin(), ssc.end());
		
		cout << solve(ssc, src) << endl;
	//}

	return 0;
}

