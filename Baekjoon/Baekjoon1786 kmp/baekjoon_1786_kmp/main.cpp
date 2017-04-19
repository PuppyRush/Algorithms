#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int>* getPi(const string &);
vector<int>* mkp(const string &,const string &, vector<int> &);

int main() {

	string src, pattern;

	cin >> src;
	cin >> pattern;

	vector<int> *pi = getPi(pattern);
	vector<int> *res = mkp(src, pattern, *pi);

	cout << res->size() << endl;
	
	for (int i = 0; i < res->size(); i++) {

		cout << res->at(i) << endl;

	}
}

vector<int>* getPi(const string &p) {
		
	vector<int> *pi = new vector<int>(p.size(), 0);
	int i = 0, j = 0;

	for (int i = 1; i < p.size(); i++) {

		while (j > 0 && j < p.size() && p[i] != p[j]) {
			j = pi->at(i-1);
		}

		if (p[i] == p[j]) {
			pi->at(i) = ++j;
		}
		
	}

	return pi;
}

vector<int>* mkp(const string &src,const string &pt, vector<int> &pi) {

	int i = 0, j = 0;
	const int srcSize = src.size();
	vector<int> *res = new vector<int>();

	for (size_t i = 0; i < srcSize; i++) {

		while (j>0 && src[i] != pt[j]) {
			j += pi[j-1];
		}

		
		if (src[i] == pt[j]) {
			
			if (j == pt.size() - 1) {
				res->push_back(i-pt.size()+1);
				j = pi[j];
			}
			else
				j++;
		}

	}

	return res;
}