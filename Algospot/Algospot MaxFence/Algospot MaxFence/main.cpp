#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) { ((a)<(b)) ? (a) : (b)}

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>


using namespace std;

typedef struct BUCKIT {
	int val;
	size_t idx;
};

int fence(const vector<BUCKIT> *src, const int, int, int);

int main() {

	int caseSize;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];
	vector<vector<BUCKIT>> *source = new vector<vector<BUCKIT>>;
	
	for (size_t i = 0; i < caseSize; i++) {

		int srcSize = 0;
		scanf("%d", &srcSize);

		vector<BUCKIT> *buckit = new vector<BUCKIT>;
		source->push_back(*buckit);

		for (size_t l = 0; l < srcSize; l++) {
			BUCKIT temp;
			scanf("%d", &(temp.val) );
			temp.idx = l;
			buckit->push_back(temp);			
		}

		result[i] = fence(&source->at(i), srcSize, 0,srcSize-1);
		
	}

	for (size_t i = 0; i < caseSize; i++) {
		
		cout << endl;
	}

}


int fence(const int *src, const int size, int length) {
	
	

}

int findMaxLength(const int )