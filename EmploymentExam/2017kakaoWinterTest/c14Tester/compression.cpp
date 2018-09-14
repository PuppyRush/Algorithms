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
#include <unordered_map>
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

typedef struct tree
{
	std::map<pair<char,char>, tree*> graph;
};

template <class T>
deque<T> getBetweenRange(T begin, T end)
{
	std::deque<T> q;
	for (T t = begin; t <= end; t++)
		q.push_back(t);
	return q;
}

vector<int> answer;
tree treehead;
std::unordered_map<string, size_t> dict;
size_t idx;

void getLengtest(deque<char>& q, char now, string& accu, tree* node)
{
	accu.push_back(now);
	q.pop_front();
	if (q.empty())
		return;

	const char next = q.front();

	auto pair = make_pair(now, next);
	if (node->graph.count(pair))
		getLengtest(q, next, accu, node->graph.at(pair));
	else
	{
		node->graph.erase(make_pair(now, 0));
		node->graph.insert(make_pair(pair,new tree));
	}
}

int recursive2(deque<char>& q)
{
	if (q.empty())
		return -1;

	const char now = q.front();
	string str;
	str.reserve(20);
	getLengtest(q, now, str, &treehead);

	if (dict.count(str))
		answer.push_back(dict.at(str));

	if (q.empty())
		return -1;

	const char next = q.front();
	str.push_back(next);
	if (dict.count(str)==0)
		dict.insert(make_pair(str, idx++));
	
	recursive2(q);
	
}

void noderemover(tree *node)
{
	if (node == nullptr)
		return;

	for (auto child : node->graph)
	{
		noderemover(child.second);
		delete child.second;
	}
	
}

vector<int> solution(string msg) {
	
	answer.reserve(1000);
	
	auto chars = getBetweenRange('A', 'Z');
	idx = 1;

	for (auto c : chars)
	{
		string s{ c };
		dict.insert(make_pair(s, idx++));
		treehead.graph.insert(make_pair( make_pair(c,0), new tree));
	}
	

	string str;
	str.reserve(1000);

	std::deque<char> q;
	for (const char c : msg)
		q.push_back(c);

	recursive2(q);
	str.clear();
	noderemover(&treehead);
	

	return answer;
}
int main() 
{
	solution("ABABABABABABABAB");

}
