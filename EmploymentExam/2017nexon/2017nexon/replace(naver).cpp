#define _CRT_SECURE_NO_WARNINGS

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

const char* replace(const char* haystack, const char* needle, const char* newword) {

	if (haystack == nullptr || needle == nullptr)
		_ASSERT(0);

	const auto hay_size = strlen(haystack);
	const auto needle_size = strlen(needle);
	const auto word_size = strlen(newword);

	if (hay_size == 0 || needle_size == 0 || word_size ==0)
		return haystack;

	int hay_idx;
	int find = 0;
	for (hay_idx = 0; hay_idx < (hay_size - needle_size) ; hay_idx++) {
		if (needle[find] == haystack[hay_idx]) {
			find++;
		}
		else {
			find = 0;
		}

		if (find == needle_size)
			break;
	}

	if (find == needle_size) {
		const size_t newlen = hay_size - needle_size + word_size;
		auto newstr = new char[newlen];
		memset(newstr, 0, sizeof(char)*newlen);
		memcpy(newstr, haystack, sizeof(char)*(hay_idx - needle_size+1));
		strcat(newstr, newword);
		strcat(newstr, haystack + hay_idx+1);
		return newstr;
	}

	return haystack;
}

int main() {

	auto haystack = "prolong a head theater mechine ";
	auto needle = "theter";
	auto word = "scott mayers";
	auto newstr = replace(haystack, needle, word);

}