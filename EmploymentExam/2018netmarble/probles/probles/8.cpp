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
//���� ����
//��� n��� ������ m���� �� A���� �� B�� �̵���Ű�� �մϴ�.�� ������ ������ ��������� ���̸�, �迡�� ����� �������� ���� �ִ� p���� Ż �� �ֽ��ϴ�.��� ó���� �� A�� �ֽ��ϴ�.�� �Ǵ� �迡�� ���������� �ڽŵ��� ���� ������� ������ ������ ������� ��ƸԽ��ϴ�.��� �� n, ������ �� m, �׸��� �迡 ž���� �� �ִ� �ִ� �ο� p�� �Ű������� �־��� ��, �ƹ��� ���� �ʰ� �����ϰ� �̵��ϱ� ���� �踦 �̵� ��Ű�� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.
//
//���ѻ���
//����� �� n�� �������� �� m�� 2 �̻� 100 ������ �ڿ����Դϴ�.
//�迡 Ż �� �ִ� �ִ� �ο� p�� 1 �̻� 10 ������ �ڿ����Դϴ�.
//�谡 �̵��ϱ� ���ؼ��� ��� �Ǵ� �������� �ּ� 1�� �̻� ž���ؾ� �մϴ�.
//�����ϰ� �̵��� �� ���ٸ� - 1�� return �ϼ���.
//����� ��
//n	m	p	result
//2	2	2	5
//2	2	1 - 1
//����� �� ����
//����� �� #1
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
//����� �� #2
//�����ϰ� �̵��� �� �ִ� ����� �����ϴ�.