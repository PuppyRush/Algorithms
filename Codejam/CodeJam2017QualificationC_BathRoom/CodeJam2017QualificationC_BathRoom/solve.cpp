#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)


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
typedef std::vector<int> VINT;
typedef std::vector<string> VSTR;

using namespace std;

int main() {

	freopen("C:\\Users\\goodd\\Downloads\\C-small-practice-2.in", "r", stdin);
	//freopen("C:\\Users\\goodd\\Desktop\\C-small1.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int t = 0; t < caseSize; ++t) {

		ULL stalls, mans;
		scanf("%llu %llu", &stalls, &mans);

		
		PINT solve;
		if (stalls != mans) {
			ULL i = 0;
			std::multimap<ULL,ULL> map;
			map.insert(pair<ULL, ULL>(stalls, stalls));

			FOR(i, mans-1) {
				auto it = prev(map.end());
				int top = it->first;
				
				int l, r;
				
				if (top % 2 == 0) {
					r = top / 2;
					l = top / 2 - 1;
				}
				else {
					l = r = top / 2;
				}				
				map.erase(it);
				map.insert(pair<ULL, ULL>(l,l));
				map.insert(pair<ULL, ULL>(r,r));
			}
			
			auto it = prev(map.end());
			ULL max, min;
			if (it->first % 2 == 0) {
				max = it->first / 2;
				min = it->first / 2 - 1;
			}
			else {
				min = max = it->first / 2;
			}
			solve = PINT(max, min);
		}
		else
			solve = PINT(0, 0);

		printf("Case #%d: %llu %llu\n", (t + 1), solve.first, solve.second);
				
	}

	return 0;
}
