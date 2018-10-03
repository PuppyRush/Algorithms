#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
	bool map[1000][1000];
	memset(&map, 0, 1000 * 1000);

	int n;
	cin >> n;
	string line;
	getline(cin, line);  // drop a newline traling n
	vector<pair<int, int>> lastest;
	lastest.reserve(n);
	while (n-- > 0) {
		stringstream ss(line);
		int pre = -1;
		int last = -1;
		for (int fork; !(ss >> fork).fail(); ) 
		{ 
			if (pre == -1)
				pre = fork;
			else
			{
				map[pre][fork] = true;
				last = fork;
			}
		}
		lastest.push_back(make_pair(pre, last));
	}

	set<int> onlyone;
	for (auto last : lastest)
	{
		
	}

	return 0;
}
