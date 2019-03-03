#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visit[50][50];
bool word[50][50];
static size_t strlens = 0;
static size_t wordcnt = 0;
vector<string> WORDS;
string endstr;

bool isConnection(const string &lhs, const string &rhs)
{
	int cnt = 0;
	for (int i = 0; i < strlens && cnt < 2; i++)
	{
		if (lhs[i] != rhs[i])
			cnt++;
	}
	return cnt == 1;
}

vector<int> cnts;

void finds(string str, int i, int cnt) {
	if (str.compare(endstr) == 0)
	{
		cnts.push_back(cnt+1);
		printf("-----\n");
		return;
	}

	for (int end = 0; end < wordcnt; end++)
	{
		if (word[i][end] && !visit[i][end])
		{
			printf("%s->%s cnt : %d \n", WORDS[i].c_str(), WORDS[end].c_str(), cnt);
			visit[i][end] = true;
			finds(WORDS[end], end, cnt + 1);
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	strlens = words[0].size();
	WORDS = words;
	wordcnt = words.size();
	endstr = target;

	for (int i = 0;  i < words.size()-1; i++)
	{
		for (int l = i + 1; l < words.size(); l++)
		{
			if (isConnection(words[i], words[l]))
			{
				word[i][l] = true;
			}
		}
	}

	for(int i=0 ; i < words.size() ; i++)
	{
		if (isConnection(begin, words[i]))
		{
			finds(begin, i, 0);
			memset(visit, 0, 50 * 50);
		}
	}

	if (cnts.empty())
		return 0;
	else
		return *std::min_element(cnts.begin(), cnts.end());
}

int main()
{
	//	"hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]

	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog"});
	return 0;
}
