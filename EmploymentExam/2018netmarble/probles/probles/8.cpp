//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int rec(std::pair<int, int> lis, std::pair<int, int> ris, pair<int,int> ship, bool left, int cnt, const int p)
//{
//	if (lis.first == 0 && lis.second == 0)
//		return cnt;
//	if (lis.first < 0 || lis.second < 0 || ris.second < 0 || ris.first < 0)
//		return -1;
//	if (lis.first>0 && lis.first < lis.second)
//		return -1;
//	if (ris.first > 0 && ris.first < ris.second)
//		return -1;
//	else if (ship.first > 0 && ship.first < ship.second)
//		return -1;
//	else if (ship.first < 0 || ship.second < 0)
//		return -1;
//	
//
//	if (left)
//	{
//		lis.first += ship.first;
//		lis.second += ship.second;
//		ris.first -= ship.first;
//		ris.second -= ship.second;
//	}
//	else
//	{
//		ris.first += ship.first;
//		ris.second += ship.second;
//		lis.first -= ship.first;
//		lis.second -= ship.second;
//	}
//
//	int min = 123456789;
//	for (int i = 0; i <= p/2; i++)
//	{
//		int c = 0;
//		if (left)
//		{
//			int human = lis.first - i;
//			int monster = lis.second - (p - i);
//			if (ship.first == human && ship.second == monster)
//				continue;
//
//			c = rec(lis, ris,make_pair(human,monster), !left, cnt + 1, p);
//		}
//		else
//		{
//			int human = ris.first - i;
//			int monster = ris.second - (p - i);
//			if (ship.first == human && ship.second == monster)
//				continue;
//
//			c = rec(lis, ris, make_pair(human, monster), !left, cnt + 1, p);
//		}
//		if (c > 0)
//			std::min(c, min);
//	}
//	return cnt+min;
//}
//
//int solution(int n, int m, int p) {
//	return rec(make_pair(n, m), make_pair(0, 0),make_pair(0,0), true, 0, p);
//}
//
//int main()
//{
//	solution(2, 2, 2);
//}
//
//문제 설명
//사람 n명과 식인종 m명을 섬 A에서 섬 B로 이동시키려 합니다.섬 사이의 유일한 교통수단은 배이며, 배에는 사람과 식인종을 합쳐 최대 p명이 탈 수 있습니다.배는 처음에 섬 A에 있습니다.섬 또는 배에서 식인종들은 자신들의 수가 사람들의 수보다 많으면 사람들을 잡아먹습니다.사람 수 n, 식인종 수 m, 그리고 배에 탑승할 수 있는 최대 인원 p가 매개변수로 주어질 때, 아무도 죽지 않고 안전하게 이동하기 위해 배를 이동 시키는 최소 횟수를 return 하도록 solution 함수를 완성해주세요.
//
//제한사항
//사람의 수 n과 식인종의 수 m은 2 이상 100 이하인 자연수입니다.
//배에 탈 수 있는 최대 인원 p는 1 이상 10 이하인 자연수입니다.
//배가 이동하기 위해서는 사람 또는 식인종이 최소 1명 이상 탑승해야 합니다.
//안전하게 이동할 수 없다면 - 1을 return 하세요.
//입출력 예
//n	m	p	result
//2	2	2	5
//2	2	1 - 1
//입출력 예 설명
//입출력 예 #1
//
//gxkleng.png
//
//image
//image
//image
//image
//image
//image
//
//입출력 예 #2
//안전하게 이동할 수 있는 방법이 없습니다.