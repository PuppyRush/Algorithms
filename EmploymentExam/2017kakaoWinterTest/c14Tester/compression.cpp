#define _CRT_SECURE_NO_WARNINGS

#define ASCII_BEGIN_ZERO 33
#define ASCII_COUNT_ALPHABET 26
#define ASCII_BEGIN_a	 97
#define ASCII_BEGIN_A	 65
#define ASCII_CASE_GAP	(ASCII_BEGIN_a - ASCII_BEGIN_A)

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <deque>
#include <queue>
#include <regex>
#include <set>
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
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;

short graph[ASCII_COUNT_ALPHABET][ASCII_COUNT_ALPHABET];

template <class T>
deque<T> getBetweenRange(T begin, T end)
{
	std::deque<T> q;
	for (T t = begin; t <= end; t++)
		q.push_back(t);
	return q;
}

vector<int> answer;
map<string, size_t> dict;
size_t idx;

int recursive(string& str, string::iterator it)
{
	if (str.end() == it)
		return -1;

	if (begin == end)
		end++;

	string buf(begin, end);
	if (dict.count(buf))
	{
		answer.push_back(dict.at(buf));
	}
	else
	{
		answer.push_back(idx);
		recursive(str, begin+1, end);
	}

	

}

vector<int> solution(string msg) {
	
	memset(graph, -1, sizeof(short)*ASCII_COUNT_ALPHABET);

	answer.reserve(1000);
	
	auto chars = getBetweenRange('A', 'Z');
	idx = 1;

	for (auto c : chars)
		dict.insert(make_pair(string{ c }, idx++));

	recursive(msg, msg.begin(), msg.begin());

	string buf;
	buf.reserve(msg.size());
	buf.push_back(*msg.begin());

	auto begin = msg.begin();
	auto end = msg.begin()+1;
	while(end != msg.end())
	{
		string buf(begin, end);
		if (dict.count(buf))
		{
			answer.push_back(dict.at(buf));
			end++;
		}
		else
		{
			answer.push_back(idx);
			dict.insert(make_pair(buf, idx++));
			begin++;
		}
	}
	
	return answer;
}
int main() 
{
	solution("KAKAO");

}
