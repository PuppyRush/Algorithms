#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

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

#define MAX 2000
#define LETTERS 'Z'-'A'+1


const char *numbers[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int order[] = { 0, 2, 4, 6, 8, 1,3,5,7,9 };

string solver(VINT letters, int remain) {

	bool added = false;
	string str;
	for(int i=0; i < 10 ; i++){
		char root = numbers[order[i]][0];
		int rootCount = letters[root];
		FOR_REV_SIZE(rootCount,1) {
			const char *self = numbers[order[i]];
			C_INT len = strlen(self);
			int l = 0;
			int min = INT32_MAX;
			FOR(l, len) 
				min = MIN(min, letters[self[l]]);
			l = 0;
			FOR(l, len)
				letters[self[l]] -= min;
			str += string(min, '0'+order[i]);
		}
		
	}
	sort(str.begin(), str.end());
	return str;

}


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

		VINT letters = VINT('Z' + 1);

		char buf[MAX + 1];
		scanf("%s", buf);
		int i = 0;
		C_INT len = strlen(buf);
		FOR(i, len) {
			letters[buf[i]]++;
		}

		i = 0;
		auto s = solver(letters,len);
		cout << "Case #" << (t + 1) << ": ";		
		cout << s << endl;
	
	}

	return 0;
}
