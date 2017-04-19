#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int MAJOR_COUNT;
int REQ_MAJOR_COUNT;
int REMANINED_SEMESTER;
int MAX_MAJOR_PER_SEMESTER;

#define INT_ int32_t

INT_ *reqMajor;
INT_ *semesterInfo;
INT_ **memo;

const int IMPOSSIBLE = 987654321;

int graduration(INT_ remainMajor, int thisSemester);
int bitCount(int bits);

int main() {

	size_t caseSize = 0;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];

	for (size_t i = 0; i < caseSize; i++) {

		scanf("%d %d %d %d", &MAJOR_COUNT, &REQ_MAJOR_COUNT, &REMANINED_SEMESTER, &MAX_MAJOR_PER_SEMESTER);

		reqMajor = new INT_[MAJOR_COUNT];
		for (size_t l = 0; l < MAJOR_COUNT; l++) {
			int reqCount = 0;
			scanf("%d", &reqCount);
			reqMajor[l] = 0;
			for (size_t t = 0; t < reqCount; t++) {
				int req;
				scanf("%d", &req);
				reqMajor[l] |=  1 << req;
			}
		}

		semesterInfo = new INT_[REMANINED_SEMESTER];
		for (size_t l = 0; l < REMANINED_SEMESTER; l++) {
			int opendMajorCount = 0;
			scanf("%d", &opendMajorCount);
			semesterInfo[l] = 0;
			for (size_t t = 0; t < opendMajorCount; t++) {
				int major;
				scanf("%d", &major);
				semesterInfo[l] |= 1 << major;
			}
		}
		
		memo = new INT_ *[REMANINED_SEMESTER];
		for (size_t l = 0; l < REMANINED_SEMESTER; l++) {
			memo[l] = new INT_[1 << MAJOR_COUNT];
			memset(memo[l],-1, sizeof(INT_)*(1<<MAJOR_COUNT));
		}
		
		result[i] = graduration(0, 0);

		for (size_t l = 0; l < REMANINED_SEMESTER; l++) {
			delete memo[l];
		}

		delete[] memo;
		delete[] reqMajor;
		delete[] semesterInfo;

	}

	for (size_t i = 0; i < caseSize; i++) {
		if (result[i] == IMPOSSIBLE)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result[i] << endl;
	}

}

int graduration(INT_ takenMajor, int thisSemester) {
	
	if (bitCount(takenMajor) >= REQ_MAJOR_COUNT)
		return 0;
	
	if (thisSemester >= REMANINED_SEMESTER)
		return IMPOSSIBLE;

	auto ref = memo[thisSemester][takenMajor];
	if (ref != -1)
		return ref;
	ref = IMPOSSIBLE;

	//아직 듣지 않은 과목 중 들을 수 있는 과목 및 들어야할 강의.
	auto possibleTakenMajor = semesterInfo[thisSemester] & ~takenMajor;
	for (int i = 0; i < MAJOR_COUNT; i++) {
		if ((possibleTakenMajor&(1 << i)) && (takenMajor & reqMajor[i]) != reqMajor[i])
			possibleTakenMajor &= ~(1 << i);
	}
	

		
	for (int take = possibleTakenMajor; take > 0; take = (take - 1)&possibleTakenMajor) {
		if (bitCount(take) > MAX_MAJOR_PER_SEMESTER)
			continue;

		int _count = graduration(takenMajor|take, thisSemester + 1) + 1;
		ref = _count < ref ? _count : ref;

	}
	

	int _count = graduration(takenMajor, thisSemester + 1);
	ref = _count < ref ? _count : ref;

	return ref;
}

int bitCount(int bits) {

	return __builtin_popcount(bits);
	//return __popcnt(bits);

}