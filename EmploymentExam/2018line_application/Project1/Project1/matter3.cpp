// CMakeProject1.cpp : Defines the entry point for the application.
//
#include <cassert>
#include <list>
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

int main()
{
	stack<size_t> st;

	constexpr const size_t len = 1000;
	char buf[len];
	std::fill_n(buf, len * sizeof(char), 0);

	scanf("%s ", buf);
	string expr(buf);

	for (const auto c : expr)
	{
		switch (c)
		{
		case '+':
			if (st.size() < 2)
			{
				assert(0);
				break;
			}
			else
			{
				const auto lhs = st.top(); st.pop();
				const auto rhs = st.top(); st.pop();
				st.push(lhs + rhs);
			}
			break;
		case '*':
			if (st.size() < 2)
			{
				assert(0);
				break;
			}
			else
			{
				const auto lhs = st.top(); st.pop();
				const auto rhs = st.top(); st.pop();
				st.push(lhs * rhs);
			}
			break;
		default:
			st.push(c - '0');
		}
	}
}
