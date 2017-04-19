#define _CRT_SECURE_NO_WARNINGS_

#include <iostream>
#include <vector>

using namespace std;

vector<int>* multiply(vector<int>*, vector<int>*);
vector<int>* normalize(vector<int>*);

int main() {

	vector<int> *s1 = new vector<int>();
	vector<int> *s2 = new vector<int>();

	char buf1[] = { "43432" };
	char buf2[] = { "3211" };

	for (int i = sizeof(buf1) / sizeof(char) - 2; i>=0 ; i--)
		s1->push_back((int)(buf1[i]-48));

	for (int i = sizeof(buf2) / sizeof(char) - 2; i >= 0; i--)
		s2->push_back((int)(buf2[i] - 48));

	cout << multiply(s1, s2);
}


vector<int>* multiply(vector<int>* s1, vector<int>* s2){

	vector<int> *result = new vector<int>(s1->size() + s2->size()+1,0);
	
	for (int i = 0; i < s1->size(); i++) {
		for (int l = 0; l < s2->size(); l++) {
			result->at(i+l) += s1->at(i) * s2->at(l);
		}
	}	

	return normalize(result);
}


vector<int>* normalize(vector<int>* dest) {

	/*int temp = 0;
	int size = dest->size();
	for (int i = 0; i < dest->size()/2; i++) {
		temp = dest->at(i);
		dest->at(i) = dest->at(size - i - 1);
		dest->at(size - i - 1) = temp;
	}
*/
	int borrow = 0;

	dest->push_back(0);
	for (int i = 0; i < dest->size()-1; i++) {

		dest->at(i+1) += dest->at(i) / 10;
		dest->at(i) %= 10;

	}

	return dest;
}

