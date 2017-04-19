
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {

	freopen("A-large-practice.in", "r", stdin); 
	freopen("A-large-practice.out", "w", stdout);
	
	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		int trueNumber = 0;
		bool digit[10];
		memset(digit, false, 10);
		int size = 0;
		scanf("%d", &size);

		char buf[100];
		size_t forLen = 0;
		sprintf(buf, "%d", size);
		if (strlen(buf) == 1)
			forLen = 100;
		else
			forLen = pow(10, strlen(buf))+1;

		int sheep = 0;
		int i = 0;
		for (i = 1; i < forLen && trueNumber != 10; ++i) {
			char buf[100];
			sheep = size*i;
			sprintf(buf, "%d", sheep);
			const size_t len = strlen(buf);
			for (int l = 0; l < len ; ++l) {
				const size_t idx = buf[l] - '0';
				if (!digit[idx]) {
					++trueNumber;
					digit[idx] = true;
				}							
			}
		}
		if (trueNumber!=10 && i == forLen) {
			std::cout << "Case #" << (l + 1) << ": INSOMNIA\n";
		}
		else
			std::cout << "Case #" << (l + 1) << ": " <<sheep << "\n";

	}

	return 0;
}
