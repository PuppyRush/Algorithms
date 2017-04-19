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


char *solver;

int main() {

	//freopen("C:\\Users\\PuppyRush_NB\\Downloads\\B-large-practice.in", "r", stdin); 
	//freopen("C:\\Users\\PuppyRush_NB\\Desktop\\B-large-practice.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		char buf[101];
		scanf("%s", buf);
		string str(buf);
		CINT len = strlen(buf);

		solver = new char[len + 1];
		memset(solver, '+', len);
		solver[len] = NULL;

		int filpCount = 0;
		while (true) {

			if (str.compare(solver) == 0)
				break;

			if (str[0] == '-') {
				size_t plus_first = string::npos;
				plus_first = str.find('+');
				if (plus_first == string::npos)
					plus_first = len;
				fill(str.begin(), str.begin() + plus_first, '+');

			}
			else {
				size_t minus_first = str.find('-', 0);
				fill(str.begin(), str.begin() + minus_first, '-');
			}

			filpCount++;
		}

		std::cout << "Case #" << (l + 1) << ": " << filpCount << "\n";
		delete solver;
		solver = nullptr;

	}

	return 0;
}
