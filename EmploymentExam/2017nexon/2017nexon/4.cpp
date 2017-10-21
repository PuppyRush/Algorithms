

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <set>
#include <queue>

using namespace std;

typedef const int C_INT;
typedef const unsigned int C_UINT;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef std::vector<std::stack<int>> S2INT;
typedef std::stack<int> SINT;
typedef std::stack<char> SCHAR;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;
typedef long long LL;

using namespace std;

string firstRepeatingLetter(string s) {

	std::map<char, set<int>> maps;

	for (int i = 0; i < s.size(); i++) {
		const char ch = s[i];
		if (maps.count(ch) == 0) {
			auto _s = set<int>();
			_s.insert(i);
			maps[ch] = _s;
		}
		else {
			maps[ch].insert(i);
		}
	}

	int minIdx = 123456789;
	for (auto it = maps.begin(); it != maps.end(); it++) {
		const auto _set = it->second;
		if (_set.size() >= 2) {
			const auto idx = *_set.begin();
			if (idx < minIdx)
				minIdx = idx;
		}
	}

	return string(1, s[minIdx]);

	/*auto indexMap = std::map<int, char>();
	auto counter = vector<int>('z' + 1, 0);
	for (int i = 0; i < s.size(); i++) {
		const char ch = s[i];
		counter[ch]++;
		
		if (indexMap.count(ch) == 0)
			indexMap[i] = ch;
		
	}

	char firstChar;
	int idx;
	for (int i = 'A'; i <= 'z'; i++) {
		if (counter[i] >= 2) {
			firstChar = i;

		}
	}

	char firstChar = indexMap.begin()->second;
	return string(1, firstChar);*/
}

int main() {
	firstRepeatingLetter("abcba");

}