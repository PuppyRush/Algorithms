//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> estimates, int k) 
//{
//	int answer = std::accumulate(estimates.begin(), estimates.begin() + k,0);
//
//	const auto len = estimates.size();
//	int presum = answer;
//	for (size_t i = 1; i <= len - k; i++)
//	{
//		int sum = presum;
//		sum -= estimates[i-1];
//		sum += estimates[i + k -1];
//		presum = sum;
//		answer = std::max(sum, answer);
//	}
//
//	return answer;
//}
//
//int main()
//{
//
//	vector<int> s;
//	s.push_back(1);
//	s.push_back(1);
//	s.push_back(9);
//	s.push_back(3);
//	s.push_back(7);
//	s.push_back(6);
//	s.push_back(5);
//	s.push_back(10);
//	solution(s, 4);
//	//[1, 1, 9, 3, 7, 6, 5, 10]
//}
//
//문제 설명
//게임에 접속한 모든 유저에게 아이템을 지급하는 출석 이벤트를 k일 동안 진행하려 합니다.날짜별 추정 접속자 수가 주어질 때, k일 동안 추정 접속자 수의 합이 최대가 되도록 이벤트 기간을 정하려 합니다.
//
//날짜별 추정 접속자 수가 순서대로 담긴 배열 estimates와 출석 이벤트를 진행하는 기간 k가 매개변수로 주어집니다.k일 동안 추정 접속자 수의 합이 최대가 되도록 이벤트 기간을 정했을 때, 그 때의 추정 접속자 수 합을 return 하도록 solution 함수를 완성해주세요.
//
//제한 조건
//estimates는 길이가 1 이상 200, 000 이하인 배열입니다.
//estimates의 원소는 10, 000 이하인 자연수입니다.
//k는 1 이상 100, 000 이하이고, estimates의 길이보다 작거나 같습니다.
//입출력 예
//estimates	k	return
//[1, 1, 9, 3, 7, 6, 5, 10]	4	28
//[1, 1, 5, 1, 1]	1	5
//예시 설명
//예시 #1
//출석 이벤트를 4일간 열려고 합니다. 4일간 추정 접속자 수의 합이 최대가 되는 경우는[7, 6, 5, 10]입니다.따라서 28을 return 하면 됩니다.
//
//예시 #2
//출석 이벤트를 하루 열려고 합니다. 1일간 추정 접속자 수의 합이 최대가 되는 경우는[5]입니다.따라서 최대 5를 return 하면 됩니다.