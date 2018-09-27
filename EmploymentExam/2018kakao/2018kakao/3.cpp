#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;


int column;
int comb;

vector<vector<int>> selection;
vector<int>	sel;

void select(int depth, int idx)
{
	if (comb == depth) {
		selection.push_back(sel);
		return;
	}
	for (int i = idx; i <= column; i++) {
		sel.push_back(i);
		select(depth + 1, i + 1);
		sel.pop_back();
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	column = relation.at(0).size();

	for (int i = 1; i < column; i++)
	{
		comb = i;
		select(0, 1);

		for (auto com : selection)
		{
			set<string> pk;
			bool exist = false;
			for (auto row : relation)
			{
				string str;
				str.reserve(100);
				for (auto _c : com)
				{
					str.append(row.at(_c-1));
				}
				if (pk.count(str) == 0)
					pk.insert(str);
				else
				{
					exist = true;
					break;
				}
			}
			if (!exist)
				answer++;
			
		}

		selection.clear();
	}

	return answer;
}

int main()
{
	vector<vector<string>> relation;
	vector<string> ary;
	ary.push_back("1");
	ary.push_back("ryan");
	ary.push_back("music");
	ary.push_back("2");
	relation.push_back(ary);
	ary.clear();

	ary.push_back("2");
	ary.push_back("apeach");
	ary.push_back("math");
	ary.push_back("2");
	relation.push_back(ary);
	ary.clear();

	ary.push_back("3");
	ary.push_back("tube");
	ary.push_back("computer");
	ary.push_back("3");
	relation.push_back(ary);
	ary.clear();

	ary.push_back("4");
	ary.push_back("con");
	ary.push_back("computer");
	ary.push_back("4");
	relation.push_back(ary);
	ary.clear();

	ary.push_back("5");
	ary.push_back("muzi");
	ary.push_back("music");
	ary.push_back("3");
	relation.push_back(ary);
	ary.clear();

	ary.push_back("6");
	ary.push_back("apeach");
	ary.push_back("music");
	ary.push_back("2");
	relation.push_back(ary);
	ary.clear();

	solution(relation);
}
