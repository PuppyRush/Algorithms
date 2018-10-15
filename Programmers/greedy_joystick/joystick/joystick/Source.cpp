#include <string>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;
size_t len;

int recursive(string str,const string& dest, int idx, bool isRight, int cnt, set<int> memo)
{
	if (memo.empty())
		return cnt;

	if (isRight)
	{
		if (idx == str.size())
			idx = 0;
		while (!memo.count(idx))
		{
			idx++;
			cnt++;
			if (idx == str.size())
				idx = 0;

		}
	}
	else
	{
		if (idx == -1)
			idx = str.size() - 1;
		while (!memo.count(idx))
		{
			idx--;
			cnt++;
			if (idx == -1)
				idx = str.size() - 1;

		}
	}

	const char c = str[idx];
	const char destc = dest[idx];
	if (c != destc)
	{
		cnt += std::min(destc - c, 'Z' - destc + ('A' - c) + 1);
		str[idx] = destc;
		memo.erase(idx);
	}
	

	auto l = recursive(str, dest, idx + 1, true, cnt+1, memo);
	auto r = recursive(str, dest, idx - 1, false, cnt+1, memo);
	if (memo.empty())
		return std::min(cnt, std::min(l, r));
	else
		return std::min(l, r);
}

int solution(string name) {
	set<int> memo;
	for (auto i=0 ; i < name.size() ; i++)
		if (name[i] != 'A')
			memo.insert(i);

	len = name.size();
	string ori(name.size(), 'A');
	return recursive(ori, name, 0, true, 0, memo);
}

int main()
{
	solution("JAZ");
}