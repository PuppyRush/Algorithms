#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b){ ((a)>(b)) ? b : a}

#include <iostream>

using namespace std;

enum CLOCK {

	TWOELVE=0,
	THREE=1,
	SIX=2,
	NINE=3
};
const int CLOCK_KIND_NUMBER = 4;
const int CLOCK_NUMBER = 16;
const int SWITCH_NUMBER = 10;

const bool switchs[10][16] = {

	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};
int clocks[CLOCK_NUMBER];

void print();
int clockRecursive(int,int);
bool countTwoelve();
void setSwitch(int switchNumber);
int eval(const int*);

int main() {

	int *result;
	
	int caseSize;
	scanf("%d", &caseSize);
	while (getchar() != '\n');

	result = new int[caseSize];

	for (int i = 0; i < caseSize; i++) {

		for (int l = 0; l < CLOCK_NUMBER; l++) {
			int temp = 0;
			scanf("%d", &temp);
			clocks[l] = (temp / 3)%CLOCK_KIND_NUMBER;
		}
		while (getchar() != '\n');

		result[i] = clockRecursive(CLOCK_NUMBER,0);
		result[i] = result[i] == 0 ? -1 : result[i];

	}

	for (int i = 0; i < caseSize; i++)
		cout << result[i] << endl;

}


int clockRecursive(int clockNumber, int thisSwitchNumber) {

	int sum = INT32_MAX
	

	if (thisSwitchNumber == CLOCK_NUMBER)
		return	countTwoelve() ? 0 : INT32_MAX;


	for (int i = 0; i < CLOCK_KIND_NUMBER; i++) {
		sum = MIN( clockRecursive(clockNumber, thisSwitchNumber+1) + i, sum);
		setSwitch(thisSwitchNumber);
	}
	
	return sum;
}

bool countTwoelve(){

	int count = 0;
	for (int i = 0; i < CLOCK_NUMBER; i++)
		if (clocks[i] != TWOELVE) {
			return false;
		}

	return true;
}

void setSwitch(int switchNumber) {
	
	
	for (int i = 0; i < CLOCK_NUMBER; i++){

		if (switchs[switchNumber][i] != 0) {
			clocks[i] = (++clocks[i]) % CLOCK_KIND_NUMBER;
		}
	}
	//print();

}

int eval(const int *clocks) {

	int eval = 0;

	for (int i = 0; i < CLOCK_NUMBER; i++) {
		eval += clocks[i] - CLOCK_KIND_NUMBER;
	}

	return eval;

}

void print()
{
	cout << endl;
	for(int i=0 ; i < CLOCK_NUMBER ; i++)
		switch (clocks[i]) {
			case TWOELVE:
				cout << "ก่";
				break;
			case THREE:
				cout << "กๆ";
				break;
			case SIX:
				cout << "ก้";
				break;
			case NINE:
				cout << "ก็";
				break;
		}

}