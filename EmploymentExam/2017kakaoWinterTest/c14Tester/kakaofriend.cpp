//#include <iostream>
//#include <vector>
//#include <string>
//#include <set>
//#include <map>
//#include <list>
//#include <deque>
//
//using namespace std;
//
//typedef enum block
//{
//	R = 'R',
//	M = 'M',
//	A = 'A',
//	F = 'F',
//	N = 'N',
//	T = 'T',
//	J = 'J',
//	C = 'C',
//	X = 'X'
//};
//
//typedef short coord;
//typedef struct Block
//{
//	coord y;
//	coord x;
//	block b;
//	
//	Block() {}
//	Block(block k, short x, short y)
//		:x(x), y(y), b(k)
//	{}
//
//	bool operator<(const Block &b)
//	{
//		if (this->x == b.x)
//			return this->y > b.y;
//		else
//			return this->x > b.x;
//	}
//};
//
//
//
//size_t height;
//size_t width;
//
//vector<vector<Block>> blocks;
//std::map<short,set<short>> removed;
//
//vector<pair<coord, coord>> bingo;
//
//
//const vector<pair<coord, coord>> getCoords(const coord y, const coord x)
//{
//	vector<pair<coord, coord>> coord;
//	for (int i = 0; i < bingo.size(); i++)
//	{
//		coord.push_back(make_pair(y + bingo[i].first, x + bingo[i].second));
// 	}
//	return coord;
//}
//
//const bool isBlocked(const Block b)
//{
//	if (b.b == X)
//		return false;
//
//	const auto size = bingo.size();
//	for (int i = 1; i < size; i++)
//	{
//		if (blocks[b.y + bingo[i].second][b.x + bingo[i].first].b != b.b)
//			return false;
//	}
//
//	return true;
//}
//
//int remove()
//{
//	size_t removedSize = 0;
//	for(int y=0 ; y < height-1 ; y++)
//		for (int x = 0; x < width-1; x++)
//		{
//			if (isBlocked(blocks[y][x]))
//			{
//				auto coords = getCoords(y, x);
//				for (auto c : coords)
//				{
//					const auto _x = c.second;
//					const auto _y = c.first;
//
//					if (removed.count(_x) == 0)
//						removed.insert(make_pair(_x, set<short>()));
//					auto &r = removed.at(_x);
//					r.insert(_y);
//					
//				}
//			}
//		}
//
//	for (auto s : removed)
//		removedSize += s.second.size();
//
//	return removedSize;
//}
//
//void goDown()
//{
//	for (const auto x_pair : removed)
//	{
//		const auto x = x_pair.first;
//		const auto y_set = x_pair.second;
//
//		set<coord, greater<coord>> exclusived;
//		for (int _y = 0; _y < height; _y++)
//			exclusived.insert(_y);
//
//		for (const auto y : y_set)
//		{
//			exclusived.erase(y);
//		}
//
//		deque<Block> newColumn;
//		for (auto y : exclusived)
//		{
//			newColumn.push_back(Block(blocks[y][x].b, x, y));
//		}
//		for (auto y : y_set)
//		{
//			newColumn.push_back(Block(X, x, y));
//		}
//		for (coord y = height-1; y >= 0 ; y--)
//		{
//			blocks[y][x] = newColumn.front();
//			blocks[y][x].y = y;
//			newColumn.pop_front();
//		}
//	}
//}
//
//int solution(int m, int n, vector<string> board) {
//	int answer = 0;
//
//	bingo.push_back(make_pair(0, 0));
//	bingo.push_back(make_pair(0, 1));
//	bingo.push_back(make_pair(1, 0));
//	bingo.push_back(make_pair(1, 1));
//
//	height = m;
//	width = n;
//
//	blocks.reserve(height);
//	for (coord y = 0; y < height; y++)
//	{
//		blocks.push_back(vector<Block>());
//		blocks[y].reserve(width);
//		for(coord x=0 ; x < width; x++)
//		{
//			blocks[y].push_back(Block(static_cast<block>(board[y][x]), x,y));
//		}
//	}
//
//	size_t removedSize = 0;
//	while ((removedSize=remove())>0)
//	{
//		goDown();
//		answer += removedSize;
//		removed.clear();
//
//		for (int y = 0 ; y < height ; y++)
//		{
//			cout << "\n";
//			for (int x = 0 ; x < width ; x++)
//			{
//				printf("%c", blocks[y][x].b);
//			}
//		}
//		cout << "\n-------------------\n";
//	}
//
//	return answer;
//}
//
//int main()
//{
//	vector<string> str;
//	str.push_back("CCBDE");
//	str.push_back("AAADE");
//	str.push_back("AAABF");
//	str.push_back("CCBBF");
//	solution(4,5, str);
//}
