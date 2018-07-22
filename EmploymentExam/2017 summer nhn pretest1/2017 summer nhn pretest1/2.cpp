#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define ALHPA_NUM	26
#define BEGIN_A_ASCII 97


void rotation(char *buf, int ro) {

	int len = strlen(buf);
	if (ro > 0) {
		for (int i = 0; i < ro; i++) {
			buf[len - 1] = buf[0];
			for (int i = 0; i < len - 1; i++) {
				buf[i] = buf[i + 1];
			}
		}
	}
	else {
		ro = -ro;
		for (int i = 0; i < ro; i++) {
			buf[0] = buf[len - 1];
			for (int i = len - 1; i > 0; i--) {
				buf[i] = buf[i - 1];
			}
		}
	}
}


string encrypt(string key, string s, int ro) {

	auto buf = new char[key.size()+1];
	for(int i=0 ; i < key.length() ; i++){

		int k = key[i] - BEGIN_A_ASCII;
		int j = s[i]-BEGIN_A_ASCII;

		buf[i] = (char)((k+j) % ALHPA_NUM) + BEGIN_A_ASCII;
	
	}
	string ss(buf);
	buf[key.size() + 1] = NULL;

	rotation(buf, ro);
	
	string newStr(buf);
	newStr.pop_back();
	return newStr;
}

string decrypt(string key, string s, int ro) {

	auto buf = const_cast<char*>(s.c_str());
	rotation(buf, -ro);
	auto _s = string(buf);
	_s.erase(_s.begin());
	for (int i = 0; i < key.length(); i++) {
		int k = key[i] - BEGIN_A_ASCII;
		int j = _s[i] - BEGIN_A_ASCII;
		if (k-j < 0) {
			buf[i] = ALHPA_NUM - (j-k) + BEGIN_A_ASCII;
		}
		else
			buf[i] = abs(k - j)%ALHPA_NUM + BEGIN_A_ASCII;
	}
	
	return string(buf);
}


int main() {

	vector<string> vec;
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
	}

	bool isEnc = true;
	if (vec[0] == "encrypt") {
		isEnc = true;
	}
	else
		isEnc = false;

	string key = vec[1];
	
	int rotate = atoi(vec[2].c_str());
	if (vec[2].size()>0 && vec[2].at(0) == '-')
		rotate = -rotate;
	
	string origin = vec[3];

	string newStr;
	if (isEnc)
		newStr = encrypt(key, origin, rotate);
	else
		newStr = decrypt(key, origin, rotate);
	

	cout << newStr;

	return 0;
}
