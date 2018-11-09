//// CMakeProject1.cpp : Defines the entry point for the application.
////
//
//#include <list>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
//#include <algorithm>
//#include <type_traits>
//#include <bitset>
//#include <iterator>
//#include <limits>
//#include <locale>
//#include <memory>
//#include <numeric>
//#include <regex>
//#include <string>
//#include <tuple>
//#include <utility>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	constexpr const size_t len = 100;
//
//	char buf[len];
//	std::fill_n(buf, len, 0);
//	scanf("%s", buf);
//
//	vector<char> chars(buf, buf + 100 * sizeof(char));
//	std::sort(chars.begin(), chars.end(), [](const char& lhs, const char&rhs)
//	{
//		return lhs > rhs;
//	});
//	
//	string non_ascending(chars.begin(), chars.end());
//	cout << non_ascending.c_str();
//
//}

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
	vector<string> expr;

	auto splited = new char[len];
	auto tokens = strtok_s(buf, " ", &splited);
	while (tokens)
	{
		string s;
		if (tokens = strtok_s(NULL, " ", &splited))
		{
			expr.emplace_back(std::move(tokens));
		}
	}

	for (const auto c : expr)
	{
		if (c.compare("+")==0)
		{
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
		}
		else if (c.compare("*") == 0)
		{
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
		}
		else
		{
			st.push(atoi(c.c_str()));
		}

	}
}
