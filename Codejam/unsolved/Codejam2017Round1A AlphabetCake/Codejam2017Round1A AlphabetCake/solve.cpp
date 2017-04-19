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
	freopen("C:\\Users\\goodd\\Downloads\\A-large-practice.in", "r", stdin);
	freopen("C:\\Users\\goodd\\Desktop\\A-large.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int t = 0; t < caseSize; ++t) {

		int r, c;
		scanf("%d %d", &r, &c);
		
		vector<string> src;
		map<char, bool> letters;
		char buf[26];
		scanf("%s", buf);
		int i = 0;
		FOR(i, r) {
			scanf("%s", buf);
			src.push_back(string(buf));
			int l = 0;
			FOR(l, c) {
				if (buf[l] != '?')
					letters[buf[l]] = true;
			}
		}

		vector<string> words;
		i = 0;
		FOR(i, r) {
			int l = 0;
			FOR(l, c) {
				if()
			}
		}

	}

	return 0;
}
