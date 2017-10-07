#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (a>b?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)


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
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;

using namespace std;

int main() {

	freopen("C:\\Users\\PuppyRush_NB\\Downloads\\A-small-practice.in", "r", stdin); 
	//freopen("C:\\Users\\PuppyRush_NB\\Desktop\\A-small-practice.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		int shySize;
		scanf("%d", &shySize);

		char *buf = new char[shySize + 2];
		scanf("%s", buf);

		int *shy = new int[shySize + 1];
		int i = 0;
		FOR(i, shySize + 1) 
			shy[i] = buf[i] - '0';
		
	
		int accu = 0;

		i = 0;
		FOR(i, shySize+1) {
			if (accu + shy[i] >= i) {// 필요이상
				accu = accu + shy[i] - i;
			}
			else if(accu+shy[i]<i){//부족
				accu += i - shy[i];
			}
		}
		int sum = (shySize * (1 + shySize)) / 2;
		if (sum <= accu)
			accu = 0;

		std::cout << "Case #" << (l + 1) << ": " << accu << "\n";
		delete shy;
	}

	return 0;
}
