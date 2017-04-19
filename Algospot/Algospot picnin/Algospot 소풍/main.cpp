#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>


using namespace std;

int recursiveFind(const int stdNumber,bool *, bool **friends);

int main() {
	
	
	int caseSize;
	scanf("%d", &caseSize);
	
	int *result = new int[caseSize];

	for (int i = 0; i < caseSize; i++) {

		int stdNumber;
		int grpNumber;
		
		scanf("%d %d", &stdNumber, &grpNumber);

		
		bool *isMated = new bool[stdNumber];
		memset(isMated, 0, sizeof(bool)*stdNumber);

		bool **friends = new bool*[stdNumber];
		for (int l = 0; l < stdNumber; l++) {
			friends[l] = new bool[stdNumber];
			memset(friends[l], 0, sizeof(bool)*stdNumber);
		}
		

		int f1, f2;
		for (int l = 0; l < grpNumber; l++) {
			scanf("%d %d", &f1,&f2);
			friends[f1][f2] = true;
			friends[f2][f1] = true;
		}

		result[i] = recursiveFind(stdNumber, isMated, friends);

	}	

	for (int i = 0; i < caseSize; i++)
		cout << result[i] << endl;

}

int recursiveFind(const int stdNumber,bool *isMated, bool **friends) {

	int matedCount = 0;
	int thisFrdIdx = -1;
	for (int i = 0; i < stdNumber; i++) {
		if (isMated[i] == false) {
			thisFrdIdx = i;
			break;
		}
	}
	if (thisFrdIdx == -1) {
		return 1;
	}

	for (int frdMateIdx = thisFrdIdx+1 ; frdMateIdx < stdNumber; frdMateIdx++) {
		if (isMated[frdMateIdx]==false &&  friends[thisFrdIdx][frdMateIdx]) {
			isMated[thisFrdIdx] = isMated[frdMateIdx] = true;
			matedCount+= recursiveFind(stdNumber, isMated, friends);
			isMated[thisFrdIdx] = isMated[frdMateIdx] = false;
		}

	}

	return matedCount;
}