#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main() {



	int caseSize;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];


	for (size_t i = 0; i < caseSize; i++) {

		int source[100000];
		int boardSize = 0;

		char temp[10001];
		scanf("%s", temp);

		size_t len = strlen(temp);
		for (size_t l = 0; l < len; l++)
			source[l] = temp[l] - 48;

		size_t mod = 0;
		int score = 0;
		bool mod5 = false;
		vector<int> accu;

		for (size_t idx = 0; idx < len; idx++) {

			const int accuLen = accu.size();
			int exNumber = 0;
			if (accuLen > 0)
				exNumber = accu[accuLen - 1];

			if (mod == 0) {
				if (accuLen >= 2) {

					int n1 = accu[accuLen - 2] - exNumber;
					int n2 = exNumber - source[idx];

					if (n1 == 0 && n2 == 0) {
						if (mod5) {
							mod5 = false;
							score += 10;
						}

						mod = 1;
					}
					else if (abs(n1)==1 && n1 == n2) {
						if (mod5) {
							mod5 = false;
							score += 10;
						}

						mod = 2;
					}
					else if (n1 == -n2) {
						if (mod5) {
							mod5 = false;
							score += 10;
						}

						mod = 3;
					}
					else if (n1 == n2) {
						if (mod5) {
							mod5 = false;
							score += 10;
						}

						mod = 4;
					}
					else {
						mod = 5;
					}

				}
				else
					accu.push_back(source[idx]);
			}

			if (mod == 1) {

				if (exNumber == source[idx] && accuLen < 4)
					accu.push_back(source[idx]);
				else{
					accu.clear();
					mod = 0;
					score += 1;
				}


			}
			else if (mod == 2) {

				if (abs(exNumber-source[idx])==1&& accuLen < 4)
					accu.push_back(source[idx]);
				else {
					accu.clear();
					mod = 0;
					score += 2;
				}
			}
			else if (mod == 3) {
				int n1 = accu[accuLen - 2] - exNumber;
				int	n2 = exNumber - source[idx];
				if( n1==-n2 && accuLen < 4)
					accu.push_back(source[idx]);
				else {
					accu.clear();
					mod = 0;
					score += 4;
				}
			}
			else if (mod == 4) {
				int n1 = accu[accuLen - 2] - exNumber;
				int	n2 = exNumber - source[idx];
				if (n1 == n2 && accuLen < 4)
					accu.push_back(source[idx]);
				else {
					accu.clear();
					mod = 0;
					score += 5;
				}
			}
			else if (mod == 5) {
				mod = 0;
				mod5 = true;
				accu.push_back(source[idx]);
			}


			
		}

		if (mod == 1)
			score += 1;
		else if (mod == 2)
			score += 2;
		else if (mod == 3)
			score += 4;
		else if (mod == 4)
			score += 5;
		else if (mod == 5)
			score += 10;

		result[i] = score;


	}

	for (int i = 0; i < caseSize; i++) {
		cout << result[i] << endl;
	}


}
