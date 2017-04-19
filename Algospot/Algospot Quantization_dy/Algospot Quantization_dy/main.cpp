#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int *memo;

typedef struct GRP {

	vector<vector<int>> src;
	float *var;
	float allAvg;
	int thisIdx;
	bool result;

};

GRP classify(GRP grp, const int grpSize, int *src, const int srcSize, int nextIdx);
float getVar(vector<int> &src);
float getVar(float *src, const int size);
int quantization(int *src, const int srcSize);

int main() {

	int caseSize;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];

	for (size_t i = 0; i < caseSize; i++) {

		int srcSize;
		int grpSize;

		scanf("%d %d", &srcSize, &grpSize);

		int *src = new int[srcSize];
		
		GRP grp;

		for (size_t l = 0; l < grpSize; l++)
			grp.src.push_back(vector<int>());

		grp.var = new float[grpSize];
		grp.allAvg = 0;
		grp.result = false;
		memset(grp.var, 0, sizeof(float)*grpSize);
		
		for (int l = 0; l < srcSize; l++) {
			int temp;
			scanf("%d", &temp);
			src[l] = temp - 48;
		}

		grp = classify(grp, grpSize, src, srcSize, 0);
		for (size_t x = 0; x < grpSize; x++) {
			for (size_t y = 0; y < grp.src[x].size(); y++)
				cout << grp.src[x][y] << " ";
			cout << endl;
		}
	
		delete[] memo;
		memo = NULL;
	}

	for (size_t i = 0; i < caseSize; i++)
		cout << result[i] << endl;
}

GRP classify(GRP grp, const int grpSize, int *src, const int srcSize, int nextIdx) {

	if (srcSize == nextIdx) {

		for (int i = 0; i < grpSize; i++) {
			if (grp.src[i].size() == 0) {
				grp.result = false;
				return grp;
			}
		}
		
		for (int i = 0; i < grpSize; i++) {
			grp.var[i] = getVar(grp.src[i]);
			grp.allAvg = getVar(grp.var, grpSize);
			
		}

		return grp;
		
	}

	GRP minGRP;
	int idx = 0;
	float minVar = 0;

	for (size_t i = 0; i < grpSize; i++) {
		if (nextIdx == 0)
			i = i;
		grp.src[i].push_back(src[nextIdx]);
		GRP tmp = classify(grp, grpSize, src, srcSize, nextIdx + 1);
		if (tmp.result == false)
			continue;

		if (tmp.allAvg < minGRP.allAvg)
			minGRP = tmp;
		
	}
	
	return minGRP;
}

float getVar(float *src, const int size) {

	float sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += src[i];
	}

	float avg = sum / size;

	float var = 0;
	for (size_t i = 0; i < size; i++) {
		var += (float)src[i] - avg;
	}

	return var*var;
}


float getVar(vector<int> &src) {

	int sum = 0;
	for (size_t i = 0; i < src.size(); i++) {
		sum += src[i];
	}

	float avg = sum/src.size();

	float var = 0;
	for (size_t i = 0; i < src.size(); i++) {
		var += (float)src[i] - avg;
	}

	return var*var;

}


//
//void classify(vector<GRP> &grp, const int grpSize, int val) {
//
//	if (grp.size() == grpSize) {
//
//		int idx = -1;
//		int gap= -1;
//
//		for (size_t i = 0; i < grp.size(); i++) {
//			int temp = abs(grp[i].average - val);
//			if (temp < gap) {
//				idx = i;
//				gap = temp;
//			}
//		}
//
//		grp[idx].src.push_back(val);
//		
//		const int size = grp[idx].src.size();
//		grp[idx].average = (val - grp[idx].average) / (size + 1);
//
//	}
//	else {
//
//
//	}
//
//
//
//
//}


int quantization(int *src, const int srcSize) {



	return 0;

}