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

inline void _fill(int *src, int begin, int end,int c) {
	int i = begin;
	FOR(i, end) {
		src[i] = c;
	}
}

int _main() {

	freopen("C:\\Users\\goodd\\Downloads\\B-small-practice.in", "r", stdin);
	freopen("C:\\Users\\goodd\\Desktop\\B-small.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		ULL solve = 0;
		int src[MAX];
		char buf[MAX];
		scanf("%s", buf);
		C_UINT len = strlen(buf);
		int i = 0;
		FOR(i, len) {
			src[i] = buf[i] - '0';
		}

		i = 0;
		
		int orderedIdx = 0;
		FOR(i, len-1) {
			if (src[i] <= src[i + 1])
				orderedIdx++;
			else
				break;
		}

		//fillZero
		FOR(i, len - 1) {
			if (src[i + 1] == 0) {
				_fill(src, i + 1, len, 0);
				break;
			}
		}

		if (orderedIdx == len-1 )
			solve = atoll(buf);
		else {
			i = len - 1;
			FOR_REV_SIZE(i,orderedIdx+2) {
				if (src[i - 1] > src[i])
					src[i - 1] = src[i];
			}
			
			char *_buf = new char[len];
					
			if (src[0] == (buf[0] - '0')) {

				src[orderedIdx] = buf[orderedIdx] - '0' - 1;

				i = orderedIdx+ 1;
				FOR(i, len)
					src[i] = 9;

				bool nonOrdered = false;
				i = len - 1;
				FOR_REV_SIZE(i,1) {
					if (src[i - 1] > src[i]) {
						src[i - 1] = src[i];
						nonOrdered = true;
					}
				}
				if (nonOrdered) {
					_buf[0] = buf[0] - 1;
					i = 1;
					FOR(i, len) {
						_buf[i] = '9';
					}
					_buf[len] = NULL;
				}
				else {
					i = 0;
					FOR(i, len) {
						_buf[i] = src[i] + '0';
					}
					_buf[len] = NULL;
				}

				if (_buf[0] == '0') {
					i = 0;
					FOR(i, len - 1) {
						_buf[i] = '9';
					}
					_buf[len-1] = NULL;
				}
			
				solve = atoll(_buf);
			}
			else {
				_buf[0] = buf[0] - 1;
				i = 1;
				FOR(i, len) {
					_buf[i] = '9';
				}
				_buf[len] = NULL;
				solve = atoll(_buf);
			}
		}		
		
		printf("Case #%d: %llu\n", (l + 1), solve);



	}

	return 0;
}
