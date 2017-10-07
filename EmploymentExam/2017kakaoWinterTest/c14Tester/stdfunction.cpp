//#include <string>
//#include <vector>
//
//using namespace std;
//
//string charArytoString(vector<char> ary);
//vector<char> intToBitArray(int x);
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2);
//string _padLeft(string s, const size_t len, const char c);
//
//int main() {
//
//	vector<int> a1;
//	a1.push_back(46);
//	a1.push_back(33);
//	a1.push_back(33);
//	a1.push_back(22);
//	a1.push_back(31);
//	a1.push_back(50);
//	vector<int> a2;
//	a2.push_back(27 );
//	a2.push_back(56 );
//	a2.push_back(19	 );
//	a2.push_back(14	 );
//	a2.push_back(14);
//	a2.push_back(10);
//
//	auto s = solution(a1.size(), a1, a2);
//
//	return 0;
//}
//
//
//
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//	vector<string> answer;
//
//	vector<int> deMap;
//	for (int i = 0; i < arr1.size(); i++) {
//		deMap.push_back(arr1[i] | arr2[i]);
//	}
//
//	auto it = deMap.begin();
//	for (; it != deMap.end(); it++) {
//		auto res = intToBitArray(*it);
//		auto str = charArytoString(res);
//		str = _padLeft(str, n, '#');
//		answer.push_back(str);
//	}
//
// 	return answer;
//}
//
//string _padLeft(string s, const size_t len, const char c) {
//
//	if (s.size() < len) {
//		return string(len - s.size(), c) + s;
//	}
//	else
//		return s;
//}
//
//vector<char> intToBitArray(int x) {
//	vector<char> res;
//	while (x) {
//		if (x & 1)
//			res.push_back('#');
//		else
//			res.push_back(' ');
//		x >>= 1;
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}
//
//string charArytoString(vector<char> ary) {
//	char *buf = new char[ary.size() + 1];
//	for (int i = 0; i < ary.size(); i++) {
//		buf[i] = ary[i];
//	}
//	buf[ary.size()] = '\0';
//	string s(buf);
//	delete[] buf;
//	return s;
//}