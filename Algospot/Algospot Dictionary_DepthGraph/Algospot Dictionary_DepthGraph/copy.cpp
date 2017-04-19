#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;
vector <vector <int>> adj;
vector <string> word;
vector <int> visitted(26, 0);
vector <int>order;
void make_g()
{

	adj = vector < vector<int> >(26, vector<int>(26, 0));

	for (int j = 1; j < word.size(); j++)
	{
		int i = j - 1, length = min(word[i].size(), word[j].size());
		for (int k = 0; k < length; k++)
		{
			if (word[i][k] != word[j][k])
			{
				int from = word[i][k] - 'a';
				int to = word[j][k] - 'a';
				adj[from][to] = 1;
				break;
			}
		}
	}
}
void dfs(int here)
{
	visitted[here] = 1;
	for (int there = 0; there < adj.size(); there++)
		if (adj[here][there] && !visitted[there])
			dfs(there);
	order.push_back(here);
}
vector<int> topologicalsort()
{
	int n = adj.size();
	visitted = vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; i++)
		if (!visitted[i])dfs(i);
	reverse(order.begin(), order.end());

	
	for(int i=0 ; i < 26 ; i++)
		cout << order[i] << " ";
	cout << "\n";


	//for(int i=0 ; i < 26 ; i++){
	//	
	//	for(int l=0 ; l < 26 ; l++){
	//		cout << adj[i][l] << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			if (adj[order[j]][order[i]])
				return vector<int>();
	}
	
	return order;
}
int _main()
{
	int test; scanf("%d", &test);
	while (test--)
	{
		int w_size; scanf("%d", &w_size);
		word = vector<string>(w_size);
		for (int i = 0; i < w_size; i++)
			cin >> word[i];
		make_g();
		order = topologicalsort();
		if (order.empty())
			printf("INVALID HYPOTHESIS");
		else
			for (int i = 0; i < order.size(); i++)printf("%c", order[i] + 'a');
		printf("\n");
	}

	return 0;
}