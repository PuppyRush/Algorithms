#include <string>
#include <vector>
#include <algorithm>
constexpr auto ALP = 'Z'-'A';

using namespace std;

bool still[20];
int total = 0;
int recursive(const string& str, const string& dest, int idx, bool isRight, int cnt)
{
	if (total == dest.size())
		return cnt;

	if (isRight && idx == str.size())
		idx = 0;
	else if (!isRight && idx == -1)
		idx = str.size() - 1;
	cnt++;

	if (!still[idx])
	{
		const char c = str[idx];
		const char destc = dest[idx];
		cnt += std::min(destc - c, 'Z' - destc - ('A' - c));

		total++;
		still[idx] = true;
	}

	return std::min(recursive(str, dest, idx + 1, true, cnt), recursive(str, dest, idx - 1, false, cnt));
}

int solution(string name) {
	int answer = 0;
	total = 0;
	string ori(name.size(), 'A');
	return recursive(ori, name, 0, true, 0);
}

int main()
{
	solution("JAZ");
}