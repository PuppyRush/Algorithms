//#include <string>
//#include <vector>
//#include <iostream>
//#include <cctype>
//#include <clocale>
//
//using namespace std;
//
//
//// http://en.cppreference.com/w/cpp/string/byte/tolower //
//bool icompare_pred(unsigned char a, unsigned char b);
//bool icompare(std::string const& a, std::string const& b);
//
//typedef struct Data {
//
//	string name;
//	int older;
//	Data()
//		:name(""), older(0) {}
//	Data(string s) :older(0) {
//		name = s;
//	}
//	void old() {
//		older++;
//	}
//
//};
//
//typedef struct Cache {
//	Cache()
//		:cacheSize(5),ratio(0){}
//	Cache(int size) :ratio(0){
//		cacheSize = size;
//	}
//
//	int ratio;
//
//private:
//	
//	vector<struct Data> caches;
//	int cacheSize;
//
//
//public:
//	size_t size() {
//		return caches.size();
//	}
//
//	void add(string s) {
//
//		if (cacheSize == 0)
//		{
//			ratio += 5;
//			return;
//		}
//
//		if (caches.size() < cacheSize)
//		{
//			if (isHit(s)) {
//				ratio += 1;
//			}
//			else {
//				caches.push_back(Data(s));
//				ratio += 5;
//			}
//		}
//		else {
//			if (isHit(s)) {
//				ratio += 1;
//			}
//			else {
//				auto it = findOlder();
//				erase(it);
//				caches.push_back(Data(s));
//				ratio += 5;
//			}
//		}
//
//		AddOld();
//	}
//	
//
//private:
//
//	void erase(vector<Data>::iterator it) {
//		caches.erase(it);
//	}
//
//	vector<Data>::iterator findOlder() {
//		vector<Data>::iterator finder;
//		int older = -1;
//		for (auto it = caches.begin(); it != caches.end(); it++) {
//			if (older < it->older) {
//				older = it->older;
//				finder = it;
//			}
//		}
//		return finder;
//	}
//
//	void AddOld() {
//		for (auto it = caches.begin(); it != caches.end(); it++) {
//			it->old();
//		}
//	}
//
//	bool isHit(string s) {
//		for (auto it = caches.begin(); it != caches.end(); it++) {
//			if (icompare(s,it->name))
//				return true;
//		}
//		return false;
//	}
//};
//
//
//
//
//int solution(int cacheSize, vector<string> cities) {
//	Cache cache(cacheSize);
//	for (auto it = cities.begin(); it != cities.end(); it++) {
//		cache.add(*it);
//	}
//	return cache.ratio;
//}
//
//
//// http://en.cppreference.com/w/cpp/string/byte/tolower //
//bool icompare_pred(unsigned char a, unsigned char b)
//{
//	return std::tolower(a) == std::tolower(b);
//}
//
//bool icompare(std::string const& a, std::string const& b)
//{
//	if (a.length() == b.length()) {
//		return std::equal(b.begin(), b.end(),
//			a.begin(), icompare_pred);
//	}
//	else {
//		return false;
//	}
//}
//// http://en.cppreference.com/w/cpp/string/byte/tolower //
//
//int main() {
//
//	vector<string> s;
//	s.push_back("jj");
//	s.push_back("pp");
//	s.push_back("ss");
//	s.push_back("ss");
//	solution(2,s);
//}
//
//
