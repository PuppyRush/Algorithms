#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <string.h>


using namespace std;

vector<int>* getPi(const string &);
int mkp(const string &src, const string &pt, vector<int> *pi);
vector<string>* wild(vector<string>*, const vector<string>&);
vector<string>* makeWildcards(string*);
vector<string> * tokenizer(string& str, const string& delimiters);

int main() {

	int caseSize;
	scanf("%d", &caseSize);

	vector<string> result;
	string *wildcard = new string[caseSize];

	for (size_t i = 0; i < caseSize; i++) {

		char buf[101];
		memset(buf, 0, 101);

		scanf("%s", &buf);
		wildcard[i] = string(buf);

		int filenameSize = 0;
		scanf("%d", &filenameSize);
		
		vector<string> filenames;
		for (size_t l = 0; l < filenameSize; l++) {

			scanf("%s", &buf);
			filenames.push_back(string(buf));

		}
		
		vector<string> *newWildcard = makeWildcards(&wildcard[i]);

		vector<string> *temp = wild(newWildcard, filenames);
		result.insert(result.end(), temp->begin(), temp->end());
	}

	for(int i=0 ; i <result.size() ; i++)
		cout << result.at(i) << endl;

}

vector<string>* wild(vector<string>* wildcard, const vector<string>& names){

	vector<string> *res = new vector<string>();
	
	size_t beginIdx = 0;
	bool ok = false;
	for (size_t nSize = 0; nSize < names.size(); nSize++) {

		string name = names.at(nSize);
		size_t wSize = 0;

		for (wSize = 0, beginIdx = 0; wSize < wildcard->size() && beginIdx < name.size(); wSize++) {

			string ch = wildcard->at(wSize);

			if (ch== "*") {
				continue;
			}

			else{
			
				vector<int> *pi = getPi(ch);
				
				if ((beginIdx = mkp(name.substr(beginIdx), ch, pi)) == string::npos) {
					break;
				}
				

			}
			
				
		}
		if (wSize == wildcard->size())
			
			if (beginIdx == name.size()-1 || (beginIdx != name.size()-1 && wildcard->at( wildcard->size()-1 ) =="*" ) ) {
				res->push_back(names.at(nSize));
		}

		ok = false;
	}


	return res;
}

vector<string>* makeWildcards(string* name) {

	size_t startIdx = name->find("*");
	size_t i = 0;
	for (i = startIdx; i < name->size() ; i++) {
		if (name->at(i) != '*')
			break;
			
	}
	if (  i-startIdx>0)
		*name =  name->erase(startIdx, i-startIdx);
	

	size_t endIdx = name->find_last_of("*");
	for (i = endIdx; i >=0 && endIdx != string::npos ; i--) {
		if (name->at(i) != '*')
			break;
	}
	if (endIdx-i>1)
		*name = name->erase(i+1, endIdx - i-1);

	vector<string> *newWild = tokenizer(*name, "*");
	if (name->at(name->size() - 1) == '*')
		newWild->push_back("*");

	return newWild;

}

vector<string> * tokenizer(string& str, const string& delimiters)
{

	vector<string> *tokens = new vector<string>;

	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// 구분자가 아닌 첫 글자를 찾는다
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token을 찾았으니 vector에 추가한다.
		tokens->push_back(str.substr(lastPos, pos - lastPos));
		
		// 구분자를 뛰어넘는다.  "not_of"에 주의하라
		lastPos = str.find_first_not_of(delimiters, pos);
		// 다음 구분자가 아닌 글자를 찾는다.
		pos = str.find_first_of(delimiters, lastPos);
		tokens->push_back( delimiters);
	}
	
	tokens->erase(tokens->end()-1);

	return tokens;
}


vector<int>* getPi(const string &p) {

	int m = (int)p.size(), j = 0;
	vector<int> *pi = new vector<int>(m, 0);
	for (int i = 1; i< m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi->at(j - 1);
		if (p[i] == p[j])
			pi->at(i) = ++j;
	}
	return pi;

}

int mkp(const string &src, const string &pt, vector<int> *pi) {

	int i = 0, j = 0;
	const int srcSize = src.size();

	for (size_t i = 0; i < srcSize; i++) {

		if (pt[j] == '?')
			j++;
		else
			while (j>0 && (src[i] != pt[j])) {
				j = pi->at(j - 1);
			}
		
		if (src[i] == pt[j] || pt[j] =='?' ) {

			if (j == pt.size() - 1) {
				return i;
			}
			else
				j++;
		}

	}

	return -1;
}