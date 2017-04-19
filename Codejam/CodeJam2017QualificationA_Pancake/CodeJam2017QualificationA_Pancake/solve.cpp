#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (a>b?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)


#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef const int CINT;
typedef unsigned int UINT;
typedef const unsigned int C_UINT;
typedef unsigned char UCHAR;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned long long ULL;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;

using namespace std;


char *solver;

void _reverse_re(char *str, C_UINT begin, C_UINT size) {
	int i = 0;
	FOR(i, size) {
		str[begin-i] = (str[begin-i] == '-' ? '+' : '-');
	}
}

void _reverse(char *str, C_UINT begin, C_UINT size) {
	int i = 0;
	FOR(i, size) {
		str[i+begin] = (str[i+begin] == '-' ? '+' : '-');
	}
}


int main() {

	freopen("C:\\Users\\goodd\\Downloads\\A-large.in", "r", stdin);
	freopen("C:\\Users\\goodd\\Desktop\\A-large.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		int flipper;
		char buf[1001];
		scanf("%s %d", buf, &flipper);
		const size_t len = strlen(buf);

		solver = new char[len + 1];

		for (int i = 0; i < len; i++)
			solver[i] = '+';
		solver[len] = NULL;

		int count = 0;
		int i = 0;
		FOR(i, len - flipper+1) {
			if (buf[i]=='-') {
				count++;
				_reverse(buf, i, flipper);
			}
		}
	
		for(i=len-1 ; i >= flipper-1 ; i--){
			if (buf[i] == '-') {
				count++;
				_reverse_re(buf, i, flipper);
			}
		}

		if (strncmp(solver, buf, len) == 0)
			std::cout << "Case #" << (l + 1) << ": " << count++ << "\n";
		else
			std::cout << "Case #" << (l + 1) << ": IMPOSSIBLE\n";
		delete solver;
		solver = nullptr;

	}

	return 0;
}
