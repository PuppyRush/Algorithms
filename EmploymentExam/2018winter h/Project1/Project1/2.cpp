#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);

	int N;
	int round;
	bool dir;
	ss >> N;
	ss >> round;
	if (round > 0)
		dir = true;
	else
		dir = false;
	vector<vector<string>> mat;
	mat.reserve(N);
	
	for (int i = 0; i < N; i++)
	{
		getline(cin, line);
		stringstream ss(line);
		vector<string> col;
		col.reserve(N);
		for (string s; !(ss >> s).fail(); )
		{
			col.push_back(s);
		}
		mat.push_back(col);
	}

	vector<vector<string>> temp;
	for (int i = 0; i < N; i++)
	{
		vector<string> col;
		col.reserve(N);
		for (int l = 0; l < N; l++)
		{
			col.push_back("");
		}
		temp.push_back(col);
	}

	int originN = N;
	while (N > 1)
	{

		int count = round % (4*(N-1));
		if (!dir)
			count = (4*(N-1)) + count;

		queue<pair<int, int>> coord;
		queue<pair<int, int>> origin;
		for (int i = 0; i < N; i++)
		{
			coord.push(make_pair(0, i));
			origin.push(make_pair(0, i));
		}
		for (int i = 1; i < N; i++)
		{
			coord.push(make_pair(i, N - 1));
			origin.push(make_pair(i, N - 1));
		}

		for (int i = N - 2; i >= 0; i--)
		{
			coord.push(make_pair(N-1, i));
			origin.push(make_pair(N-1, i));
		}

		for (int i = N - 2; i > 0; i--)
		{
			coord.push(make_pair(i, 0));
			origin.push(make_pair(i, 0));
		}

		while (count-- > 0)
		{
			auto c = coord.front();
			coord.pop();
			coord.push(c);
		}


	
		while (!coord.empty())
		{
			auto c = coord.front();
			auto ori = origin.front();
			ans[c.first][c.second] = mat[ori.first][ori.second];
			coord.pop();
			origin.pop();
		}



		N--;
		dir = !dir;
	}

	for (int i = 0; i < originN; i++)
	{
		for (int l = 0; l < originN; l++)
		{
			cout << ans[i][l];
			if (l != originN - 1)
				cout << " ";
		}
		cout << endl;
	}


	round /= N;
}