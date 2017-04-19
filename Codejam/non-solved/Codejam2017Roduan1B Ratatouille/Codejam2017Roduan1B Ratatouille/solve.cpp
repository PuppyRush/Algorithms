#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)
#define FOR_EACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

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

inline int getPer(C_INT basic, C_INT percent) {
	int per = basic / 100;
	return percent >= 100 ? (basic - per*(100 - percent)) : (basic + per*(percent - 100));
}

int solve(C_V2INT src,C_INT_P regi,C_INT packages, C_INT nCount, C_INT ex, C_INT sol) {

	if (sol == nCount)
		return 1;
	if (nCount == ex)
		return -1;
	
	int ref = 0;
	int i = ex;
	FOR(i, nCount) {
		int l = 0;
		FOR(l, packages){
			cout << src[i][l] << " " << regi[i] << endl;
			if (src[i][l] % regi[i] == 0) {
				int t = solve(src, regi, packages, nCount, i + 1, sol+1);
				if (t > 0)
					ref += t;
			}
		}	
	}
	return ref;
}

int main() {
	//freopen("C:\\Users\\goodd\\Downloads\\A-large-practice.in", "r", stdin);
	//freopen("C:\\Users\\goodd\\Desktop\\A-large.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int t = 0; t < caseSize; ++t) {

		int nCount, package;
		scanf("%d %d", &nCount, &package);
		
		int *basic = new int[nCount];
		V2INT packages = V2INT(nCount, VINT());
		int i = 0;
		FOR(i, nCount)
			scanf("%d", &basic[i]);
		i = 0;
		int l = 0;
		FOR(i, nCount) {
			l = 0;
			FOR(l, package) {
				int tmp;
				scanf("%d", &tmp);
				packages[i].push_back(tmp * 100);
			}
		}

		int rata = 0;
		i = 0;
		FOR(i, 21) {
			int *serving = new int[nCount];
			l = 0;
			FOR(l, nCount) {
				serving[l] = getPer(basic[l]*100, 90 + i);
			}
			
			rata += solve(packages, serving,package, nCount,0,0);

			//int completed=0;
			//int ex = 0;
			//l = 0;
			//FOR(l, nCount) {
			//	int p = 0;
			//	FOR(p,package)
			//		if ((packages[l][p] % serving[l]) == 0) {
			//			break;
			//		}
			//	if (p != package) {
			//		completed++;
			//	}
			//}
			//if (completed == nCount) {
			//	rata.push_back(i);
			//}
			//completed = 0;
		}

		cout << "Case #" << (t + 1) << ": " << rata << endl;
	}

	return 0;
}
