#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#define MIN(a,b) (((a)<(b)) ? (a) : (b))

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>


using namespace std;

int memo[100];

int main() {

	string s("sdad");
	const char *c = s.c_str();
	cout << c[2];

	/*vector<int> result;
	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		memset(memo, -1, sizeof(int) * 100);


	}
*/

}