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

#define MAX 20

C_ULL solve(char *str) {

	int len = strlen(str);
	int i = len - 1;
	FOR_REV_SIZE(i, 1){
		int higher = str[i-1] - '0';
		int lower = str[i] - '0';
		if (higher > lower) {
			str[i-1] = (higher - 1) + '0';
			memset(str + i, '9', (len-i));
		}			
	}

	return atoll(str);
}

int main() {

	freopen("C:\\Users\\goodd\\Downloads\\B-large-practice.in", "r", stdin);
	freopen("C:\\Users\\goodd\\Desktop\\B-large.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {
				
		char buf[MAX];
		scanf("%s", buf);
		printf("Case #%d: %llu\n", (l + 1), solve(buf));



	}

	return 0;
}
