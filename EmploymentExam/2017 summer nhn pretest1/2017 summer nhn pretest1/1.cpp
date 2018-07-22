//#define _CRT_SECURE_NO_WARNINGS
//
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//typedef struct Data {
//
//	int item;
//	int older;
//	Data()
//		:item(-1), older(0) {}
//	Data(int s) :older(0) {
//		item = s;
//	}
//	void old() {
//		older++;
//	}
//
//};
//
//typedef struct Cache {
//	Cache()
//		:cacheSize(5), isNotErase(true){}
//	Cache(int size):isNotErase(true){
//		cacheSize = size;
//	}
//
//	bool isNotErase;
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
//	int add(int item) {
//
//		int oldItem = -1;
//		if (cacheSize == 0)
//		{
//			return -1;
//		}
//
//		if (caches.size() < cacheSize)
//		{
//			if (!isHit(item)) {
//				caches.push_back(Data(item));
//			}
//		}
//		else {
//			if (!isHit(item)) {
//				auto it = findOlder();
//				oldItem = erase(it);
//				caches.push_back(Data(item));
//				isNotErase = false;
//			}
//			else
//			{
//				auto it = findOlder();
//				invalidItem(it);
//			}
//		}
//
//		AddOld();
//		return oldItem;
//	}
//
//
//private:
//
//	int erase(vector<Data>::iterator it) {
//		int item = it->item;
//		caches.erase(it);
//		return item;
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
//	bool isHit(int s) {
//		for (auto it = caches.begin(); it != caches.end(); it++) {
//			if (s == it->item)
//			return true;
//		}
//		return false;
//	}
//
//	void invalidItem(vector<Data>::iterator it) {
//		it->older = 0;
//	}
//};
//
//
//
//int main(int argc, char *argv[]){
//
//	vector<int> s;
//	for (int i = 0; i < argc; i++) {
//		int temp = -1;
//		scanf("%d", argv[0]);
//		s.push_back(temp);
//	}
//	
//	Cache cache(3);
//	
//	for (auto it = s.begin(); it != s.end(); it++) {
//		int item =cache.add(*it);
//		if (item > -1)
//			printf("%d\n", item);
//	}
//	if (cache.isNotErase)
//		printf("0\n");
//
//	return 0;
//}
//
//
