#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <stack>
using namespace std;

vector<bool> result;

bool bracket(const string &src);

int main() {


	size_t caseSize = 0;
	scanf("%d", &caseSize);
	
	for (size_t i = 0; i < caseSize; i++) {

		
		string src;
		cin >> src;

		result.push_back(bracket(src));
	}

	size_t l = 0;
	FOR(l, result.size()) {
		if (result[l])
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}

}

bool bracket(const string &src) {

	std::stack<char> st;

	auto it = src.begin();
	while (it != src.end()) {
		char top = NULL;
		char c = *it;
		
		switch (c) {
			case '[':	case '{':	case '(':
				st.push(c);
				break;

			case '}':	case ')':	case ']':
				if (st.size() == 0)
					return false;
				else {
					top = st.top();
					if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
						st.pop();
					else
						return false;
				}
				break;
			default:
				return false;
				break;

		}

		it++;
	}

	return st.size() == 0;
}