//#include <string>
//#include <vector>
//#include <algorithm>
//#include <regex>
//
//using namespace std;
//
//typedef enum Zone {
//	S,
//	D,
//	T,
//	NOTHING
//};
//
//typedef enum Option {
//	special,
//	acha,
//	NOTHINGS
//};
//
//typedef struct GAME {
//
//	Option option;
//	int point;
//	Zone zone;
//	GAME()
//		:option(Option::NOTHINGS),zone(Zone::NOTHING),point(0)
//	{
//
//	}
//
//};
//
//vector<vector<char>*> split(string s);
//vector<GAME> GetGames(vector<vector<char>*> splited);
//void ProcessSpecial(vector<GAME>& games);
//string intToBitString(int x);
//string padLeft(string s, const size_t len, const char c);
//
//int solution(string dartResult) {
//
//	int answer = 0;
//	auto splited = split(dartResult);
//	auto games = GetGames(splited);
//	ProcessSpecial(games);
//	for (auto it = games.begin(); it != games.end(); it++)
//		answer += it->point;
//	return answer;
//}
//
//
////vector<vector<char>*> split(string s) {
////
////	vector<vector<char>*> ary;
////	auto buf = new vector<char>();
////	for (auto it = s.begin(); it != s.end(); it++) {
////
////		switch (*it) {
////
////		case 'S':
////		case 'D':
////		case 'T':
////			buf->push_back(*it);
////			if (it != s.end() - 1 && (*(it + 1)) != '#' && (*(it + 1)) != '*')
////			{
////				ary.push_back(buf);
////				buf = new vector<char>();
////			}
////			break;
////		case '#':
////		case '*':
////			buf->push_back(*it);
////			ary.push_back(buf);
////			buf = new vector<char>();
////			break;
////		case '1':
////		case '0':
////		case '2':
////		case '3':
////		case '4':
////		case '5':
////		case '6':
////		case '7':
////		case '8':
////		case '9':
////			if (*it == '1') {
////				if (it + 1 != s.end() && (*(it + 1)) == '0') {
////					buf->push_back('A');
////					it++;
////				}
////				else
////					buf->push_back(*it);
////			}else
////				buf->push_back(*it);
////			break;
////		}
////	}
////	if(!buf->empty())
////		ary.push_back(buf);
////	return ary;
////}
//
//vector<vector<char>*> split(string s) {
//
//	vector<vector<char>*> ary;
//	const auto tokenizer = std::regex("\[123][SDT][*#]?");
//
//	std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), tokenizer);
//	std::regex_iterator<std::string::iterator> rend;
//
//	while (rit != rend) {
//		auto str = rit->str();
//		rit++;
//	}
//
//	return ary;
//}
//
//
//vector<GAME> GetGames(vector<vector<char>*> splited) {
//
//	vector<GAME> games;
//	for (auto it = splited.begin(); it != splited.end(); it++) {
//		GAME g;
//		if ((*it)->at(0) == 'A')
//			g.point = 10;
//		else
//		g.point = (*it)->at(0) - 48;
//
//		switch ((*it)->at(1)) {
//		case 'S':
//			g.zone = Zone::S;
//			break;
//		case 'D':
//			g.point = pow(g.point, 2);
//			g.zone = Zone::D;
//			break;
//		case 'T':
//			g.point = pow(g.point, 3);
//			g.zone = Zone::T;
//			break;
//		}
//
//		if ((*it)->size() == 3)
//		{
//			switch ((*it)->at(2)) {
//			case '*':
//				g.option = Option::special;
//				break;
//			case '#':
//				g.option = Option::acha;
//				break;
//			default:
//				g.option = Option::NOTHINGS;
//			}
//		}
//		games.push_back(g);
//	}
//	return games;
//}
//
//void ProcessSpecial(vector<GAME>& games) {
//
//	const size_t len = games.size();
//	string str;
//	for (int i = 0; i < len; i++) {
//		switch (games[i].option) {
//		case Option::special:
//			str = "01" + str;
//			break;
//		case Option::acha:
//			str = "10" + str;
//			break;
//		case Option::NOTHINGS:
//			str = "00" + str;
//		}
//	}
//	if (str == "000001")
//		games[0].point *= 2;
//	else if (str == "000100") {
//		games[1].point *= 2;
//		games[0].point *= 2;
//	}
//	else if (str == "010000") {
//		games[2].point *= 2;
//		games[1].point *= 2;
//	}
//	else if (str == "000101")
//	{
//		games[0].point *= 4;
//		games[1].point *= 2;
//	}
//	else if (str == "010100")
//	{
//		games[1].point *= 4;
//		games[2].point *= 2;
//	}
//	else if (str == "010001")
//	{
//		games[0].point *= 4;
//		games[2].point *= 2;
//	}
//	else if (str == "100000")
//	{
//		games[2].point = -games[2].point;
//	}
//	else if (str == "001000")
//	{
//		games[1].point = -games[1].point;
//	}
//	else if (str == "000010")
//	{
//		games[0].point = -games[0].point;
//	}
//	else if (str == "100100")
//	{
//		games[1].point *= 2;
//		games[2].point = -games[2].point;
//		games[2].point *= 2;
//	}
//	else if (str == "011000")
//	{
//		games[2].point *= 2;
//		games[1].point = -games[1].point;
//		games[1].point *= 2;
//	}
//	else if (str == "001001")
//	{
//		games[0].point *= 2;
//		games[1].point = -games[1].point;
//		games[1].point *= 2;
//	}
//	else if (str == "000110")
//	{
//		games[1].point *= 2;
//		games[0].point = -games[0].point;
//		games[0].point *= 2;
//	}
//	else if (str == "100001")
//	{
//		games[0].point *= 2;
//		games[2].point = -games[2].point;
//		games[2].point *= 2;
//	}
//	else if (str == "010010")
//	{
//		games[2].point *= 2;
//		games[0].point = -games[0].point;
//		games[0].point *= 2;
//	}
//
//
//	else if (str == "010010")
//	{
//		games[2].point *= 2;
//		games[0].point = -games[0].point;
//		games[0].point *= 2;
//	}
//	else if (str == "101010")
//	{
//		games[2].point = -games[2].point;
//		games[1].point = -games[1].point;
//		games[0].point = -games[0].point;
//	}
//	else if (str == "101000")
//	{
//		games[1].point = -games[1].point;
//		games[0].point = -games[0].point;
//	}
//	else if (str == "001010")
//	{
//		games[1].point = -games[1].point;
//		games[2].point = -games[2].point;
//	}
//	else if (str == "100010")
//	{
//		games[0].point = -games[0].point;
//		games[2].point = -games[2].point;
//	}
//
//}
//
//string intToBitString(int x) {
//	string str;
//	while (x) {
//		if (x & 1)
//			str.push_back('1');
//		else
//			str.push_back('0');
//		x >>= 1;
//	}
//	reverse(str.begin(), str.end());
//	return str;
//}
//
//
//string padLeft(string s, const size_t len, const char c) {
//
//	if (s.size() < len) {
//		return string(len - s.size(), c) + s;
//	}
//	else
//		return s;
//}
//
//
//int main() {
//	solution("1T2D3D#");
//}
