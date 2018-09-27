//#include <string>
//#include <vector>
//#include <set>
//#include <map>
//using namespace std;
//
//typedef struct coord
//{
//	short y;
//	short x;
//	short idx;
//}coord;
//
//int* node;
//map<int, set<pair<int, int>>, greater<int>> coords;
//int height;
//
//void recursive(const int x, const int y)
//{
//	int size = (1 << (height - y));
//	int startidx = size - 1;
//
//	auto xset = coords.at(y);
//	for (auto _x : xset)
//	{
//
//	}
//}
//
//vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
//	vector<vector<int>> answer;
//
//	node = new int[131072]; //2^17
//	memset(node, 0, sizeof(int) * 131072);
//
//	for(int i=0; i < nodeinfo.size() ; i++)
//	{
//		coord c;
//		c.idx = i+1;
//		c.y = nodeinfo.at(i).at(1);
//		c.x = nodeinfo.at(i).at(0);
//
//		if (coords.count(c.y))
//			coords.at(c.y).insert(make_pair(c.x, c.idx));
//		else
//		{
//			set<pair<int, int>> s;
//			s.insert(make_pair(c.x, c.idx));
//			coords.insert(make_pair(c.y, s));
//		}
//	}
//
//	int height = coords.begin()->first;
//	recursive(coords.begin()->second.begin()->first, coords.begin()->first);
//	/*
//	for (auto c : coords)
//	{
//		for (auto xset : c.second)
//		{
//			int startidx = height - c.first;
//
//		}
//	}*/
//
//	return answer;
//}
//int main()
//{
//	//[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
//	vector<vector<int>> nodeinfo;
//	vector<int> n;
//	n.push_back(5);
//	n.push_back(3);
//	nodeinfo.push_back(n);
//	n.clear();
//	n.push_back(11);
//	n.push_back(5);
//	nodeinfo.push_back(n);
//	n.clear();
//
//	n.push_back(13);
//	n.push_back(5);
//	nodeinfo.push_back(n);
//	n.clear();
//
//	n.push_back(3);
//	n.push_back(5);
//	nodeinfo.push_back(n);
//
//	n.push_back(6);
//	n.push_back(1);
//	nodeinfo.push_back(n);
//	n.clear();
//	n.push_back(1);
//	n.push_back(3);
//	nodeinfo.push_back(n);
//	n.clear();
//	n.push_back(8);
//	n.push_back(6);
//	nodeinfo.push_back(n);
//	n.clear();
//	n.push_back(7);
//	n.push_back(2);
//	nodeinfo.push_back(n);
//	n.clear();
//	n.push_back(2);
//	n.push_back(2);
//	nodeinfo.push_back(n);
//	n.clear();
//	solution(nodeinfo);
//}
