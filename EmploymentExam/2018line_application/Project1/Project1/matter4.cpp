#include <cassert>
#include <list>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <bitset>
#include <iterator>
#include <limits>
#include <locale>
#include <memory>
#include <numeric>
#include <regex>
#include <string>
#include <tuple>
#include <utility>
#include <iostream>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

//typedef struct dataset
//{
//	size_t age;
//	size_t value;
//	dataset(const size_t _age, const size_t _val)
//		:age(_age), value(_val)
//	{}
//};
//
//class comprator
//{
//	using express = std::function<bool(const dataset lhs, const dataset rhs)>;
//	
//	std::set<dataset, express> compset;
//	express comp;
//
//	comprator()
//	{
//		comp = [](const dataset lhs, const dataset rhs) -> bool
//		{
//			return true;
//		};
//	}
//};
#undef max

//#define max = 1079741824
using type = size_t;
constexpr const type error = std::numeric_limits<type>::max();

class comprator
{
	using comptype = std::list<type>;
	using it = comptype::iterator;
	
	comptype m_train;
	it minpos;
	const it end;

public:
	comprator()
		:end(m_train.begin())
	{
		minpos = m_train.begin();
	}

	void add(const type val)
	{
		m_train.push_back(val);
		if (minpos == end)
			minpos = m_train.begin();

		if (*minpos > val)
			minpos = --m_train.end();
	}

	type remove()
	{
		if (m_train.empty() || minpos == end)
		{
			return error;
		}
		else
		{
			auto _minpos = m_train.begin();
			auto min = *_minpos;
			m_train.erase(_minpos);

			return min;
		}
	}

	type min()
	{
		if (minpos == end)
		{
			return error;
		}
		else
			return *minpos;
	}
};

int main()
{
	comprator comp;

	regex addreg("add [\\d]*");
	regex removereg("remove");
	regex minreg("min");
	regex exitreg("exit");

	vector<type> answer;
	answer.reserve(100);

	while (1)
	{
		char buf[100];

		cin.getline(buf,100);
		string str(buf);

		if (std::regex_match(str, addreg))
		{
			const auto pos = str.find(' ');
			const string strnum = str.substr(pos + 1);
			comp.add(atoi(strnum.c_str()));
		}
		else if (std::regex_match(str, removereg))
		{
			answer.push_back(comp.remove());
		}
		else if (std::regex_match(str, minreg))
		{
			answer.push_back(comp.min());
		}
		else if (std::regex_match(str, exitreg))
		{
			break;
		}
		else
		{
			;
		}
	}
}