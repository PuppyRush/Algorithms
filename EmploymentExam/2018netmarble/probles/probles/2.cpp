////#include <string>
////#include <vector>
////#include <unordered_map>
////
////using namespace std;
////
////vector<long long> solution(vector<string> words) {
////	vector<long long> answer;
////
////	std::unordered_map<string,long long> round;
////	const auto len = words.size();
////	for(size_t i=0 ; i < len ; i++)
////	{
////		const auto str = words[i];
////		if (!round.count(str))
////			round.insert(make_pair(str, i + 1));
////
////		answer.push_back(round.at(str));
////	}
////
////	return answer;
////}
//
//문제 설명
//Verbal memory 게임에서 게이머는 각 라운드마다 주어진 단어가 몇 번째 라운드에서 나왔던 단어인지 판단해야 합니다.예를 들어, 4 라운드 게임에서 각 라운드마다 단어가 다음같이 주어진 경우, [one, one, two, one]
//
//1 라운드: 단어 one이 주어졌으며, 이 단어는 이번 라운드에 처음으로 등장한 단어입니다.
//2 라운드 : 단어 one이 주어졌으며, 이 단어는 1 라운드에서 처음으로 등장했습니다.
//3 라운드 : 단어 two가 주어졌으며, 이 단어는 이번 라운드에 처음으로 등장한 단어입니다.
//4 라운드 : 단어 one이 주어졌으며, 이 단어는 1 라운드에서 처음으로 등장했습니다.
//따라서 각 라운드에 주어진 단어는[1, 1, 3, 1] 라운드에 처음으로 등장했습니다.
//
//각 라운드마다 주어진 단어를 순서대로 저장한 배열이 주어질 때, 해당 단어가 몇 라운드에서 처음 등장했는지 리턴하는 함수, solution을 작성하세요.
//
//제한 조건
//한 게임은 1 라운드 이상, 200, 000 라운드 이하로 구성됩니다.
//라운드마다 주어지는 단어는 영문 소문자로만 구성됩니다.
//라운드마다 주어지는 단어의 길이는 1 이상, 30 이하입니다.
//입출력 예
//words	return
//[one, one, two, one][1, 1, 3, 1]
//[may, with, may, you, you][1, 2, 1, 4, 4]
//입출력 예 설명
//입출력 예 #1
//
//앞서 설명한 예시와 같습니다.
//
//입출력 예 #2
//
//라운드 수	주어진 단어	결과	결과 이유
//1	may	1	처음 등장한 단어
//2	with	2	처음 등장한 단어
//3	may	1	1 라운드에 나온 단어
//4	you	4	처음 등장한 단어
//5	you	4	4 라운드에 나온 단어