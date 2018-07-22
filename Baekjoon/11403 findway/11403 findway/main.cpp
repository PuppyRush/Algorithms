#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> paths;
bool** visited;

void find(vector<int>& pasts, const int start, const int i)
{
	for (const auto next : paths.at(i))
	{
		if (visited[i][next])
			continue;

		visited[i][next] = true;

		if (next == start)
			continue;

		pasts.push_back(next);
		for (const auto past : pasts)
			visited[past][next] = true;

		find(pasts, start, next);
		pasts.pop_back();

	}

}

int main()
{

	int size = 0;
	scanf("%d", &size);

	visited = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		paths.push_back(vector<int>());
		paths.at(i).reserve(size);
		visited[i] = new bool[size];
		for (int l = 0; l < size; l++)
		{
			visited[i][l] = false;
			int path = 0;
			scanf("%d ", &path);
			if (path == 1)
				paths.at(i).push_back(l);
		}
		//	while( getchar() != '\n' );
	}

	for (int i = 0; i < size; i++)
	{
		vector<int> pasts;
		pasts.reserve(size);
		pasts.push_back(i);
		find(pasts, i, i);
	}
	for (int i = 0; i < size; i++)
	{
		for (int l = 0; l < size; l++)
			printf("%d ", visited[i][l]);
		printf("\n");
	}
	return 0;
}
