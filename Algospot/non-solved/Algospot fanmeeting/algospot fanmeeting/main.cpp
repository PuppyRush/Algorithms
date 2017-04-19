#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) { ((a)<(b)) ? (a) : (b)}
#define MAXSIZE 200000

#include <iostream>
#include <vector>
#include <string.h>



using namespace std;

typedef struct BUCKIT {
	int left;
	int right;
};

int fanmeeting(const char* fan, int fanN, int idolN, vector<BUCKIT>* manTrain);

int main() {

	int caseSize;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];
	char *idol;
	char *fan;
		
	for (size_t i = 0; i < caseSize; i++) {

		char buf[MAXSIZE];
		memset(buf, 0, MAXSIZE);
	
		scanf("%s", buf);
		size_t idolNumber = strlen(buf);
		idol = new char[idolNumber+1];
		memset(idol, 0, idolNumber + 1);
		memcpy(idol, buf, idolNumber);

		vector<BUCKIT> manTrain;
		int begin, count = 0;
		for (int l = 0, begin=0 ; l < idolNumber; l++) {
			
			if (idol[l] == 'M') {

				begin = l;

				while (l < idolNumber && idol[l] == 'M' && idol[l + 1] == 'M') {
					count++;
					l++;
				}

				BUCKIT buckit;
				buckit.left = begin;
				buckit.right = begin + count;
				manTrain.push_back(buckit);

				count = 0;
			}
		}

		scanf("%s", buf);
		size_t fanNumber = strlen(buf);
		fan= new char[fanNumber+1];
		memset(fan, 0, fanNumber + 1);
		memcpy(fan, buf, fanNumber);


		result[i] = fanmeeting(fan, fanNumber, idolNumber, &manTrain);

		delete idol;
		delete fan;
		

	}

	for (int i = 0; i < caseSize; i++)
		cout << result[i] << endl;

}

int fanmeeting(const char* fan,int fanN, int idolN, vector<BUCKIT>* manTrain) {

	int val = 0;

	bool ok = true;
	size_t begin, end;
	size_t t = 0;
	
	if (manTrain->size() == 0)
		return fanN - idolN + 1;

	for (size_t i = 0; i <= (size_t)(fanN - idolN); i++) {
		for (; t < manTrain->size(); t++) {
			begin = manTrain->at(t).left + i;
			end = manTrain->at(t).right + i;

			for (size_t l = begin; l <= end; l++) {
				if (fan[l] == 'M') {
					ok = false;
					t = manTrain->size();
					break;
				}

			}

		}
		if (ok)
			val++;		

		ok = true;
		t = 0;
	}

	return val;
}