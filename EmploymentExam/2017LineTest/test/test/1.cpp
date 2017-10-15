//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <numeric>
//
//using namespace std;
//
///*
//* Description :
//* Time complexity :
//* Space complexity :
//*/
//int calc(vector<int> &numbers) {
//	
//	int newCount = 0;
//	auto count = numbers.size();
//	int accu = std::accumulate(numbers.begin(), numbers.end(), 0.0);
//	float avg = (float)accu/(float)count;
//
//	while (avg <= 9.5) {
//		newCount++;
//		count++;
//		accu += 10;
//		avg = (float)accu / (float)count;
//	}
//
//	return newCount-1;
//}
//
//int main(int argc, const char* argv[]) {
//	int n = 0;
//	scanf("%d", &n);
//
//	vector<int> numbers(n);
//	for (int i = 0; i<n; i++) {
//		int score = 0;
//		scanf("%d", &numbers[i]);
//	}
//
//	cout << calc(numbers) << endl;
//}