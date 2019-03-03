#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char word[24];
size_t strlens = 0;

int findpath(const vector<string>& ary, const vector<string>::const_iterator it, string exstr ,const string end, int changes )
{
	if (exstr.compare(end) == 0)
		return changes;

	int wrong = 0, i = 0;
	for( i=0; i < strlens && wrong <2; i++)
	{
		if (exstr[i] != (*it)[i])
			wrong++;
	}
	if (wrong >= 2)
		return -1;

	for (auto newit = ary.cbegin(); newit != ary.cend(); ++newit)
	{
		if (newit == it || newit->compare(exstr)==0)
			continue;

		if (int paths = findpath(ary, newit, *it, end, changes + 1))
			changes = std::min(changes, paths);
	}

	return changes;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	for (int i = 0; i < begin.size();)
	{
		if (begin[i] == target[i])
		{
			begin.erase(i);
			target.erase(i);

			for (auto str : words)
			{
				str.erase(i);
			}
		}
		else
			++i;
	}

	strlens = begin.size();
	answer = findpath(words, words.cbegin(), begin, target, 0);

	return answer;
}

int main()
{
	//	"hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]

	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	return 0;
}
