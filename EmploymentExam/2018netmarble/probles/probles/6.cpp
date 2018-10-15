////#include <iostream>
////#include <string>
////#include <vector>
////#include <queue>
////#include <map>
////using namespace std;
////
////int memo[46];
////
////long rec(queue<int> eggs, queue<int> dragons,const int start, int remain)
////{
////	if (remain == -1)
////	{
////		memo[start] = eggs.size() + dragons.size();
////		return eggs.size() + dragons.size();
////	}
////
////	if (memo[start] > 0)
////		return memo[start];
////
////	queue<int> newEggs;
////	while (!eggs.empty())
////	{
////		int egg = eggs.front();
////		eggs.pop();
////		if (egg == 0)
////			dragons.push(4);
////		else
////			newEggs.push(egg - 1);
////	}
////	long sum = 0;
////	queue<int> newDragons;
////	int dead = 0;
////	while (!dragons.empty())
////	{
////		int dragon = dragons.front();
////		dragons.pop();
////		
////		if (dragon > 0)
////		{
////			newDragons.push(dragon - 1);
////			queue<int> egg;
////			queue<int> dra;
////			egg.push(2);
////			sum += rec(egg, dra, remain, remain);
////		}
////		else
////			dead++;
////
////		
////	}
////
////	return sum + rec(newEggs, newDragons, remain, remain - 1) + dead;
////}
////
////int solution(int n) {
////	
////	memset(memo, 0, 46);
////	queue<int> egg;
////	queue<int> dra;
////	egg.push(2);
////	return rec(egg, dra,n, n);
////}
////
////int main()
////{
////	solution(45);
////}
//
//���� ����
//������ ���� �����ϴ� �巡���� �ֽ��ϴ�.�� ���� �巡�� �� �ϳ��� ������ �������� ��, n�� �Ŀ� �巡��� �巡�� ���� �� ������ �˾Ƴ��� �մϴ�.
//
//�巡�� ���� ��Ʋ �ڿ� ��ȭ�մϴ�.
//��ȭ�� �巡���� ���� ���� �ϳ��� �����ϴ�.
//��ȭ�� �巡���� �� �� ���� ���� ��, �� �̻� ���� ���� �ʽ��ϴ�.
//n�� �Ű������� �־��� ��, n�� �� �巡��� �巡�� ���� �� �� �ִ��� return �ϴ� solution �Լ��� �ϼ����ּ���.
//
//���� ����
//n�� 45 ������ �ڿ����Դϴ�.
//����� ��
//n	return
//6	12
//����� �� ����
//�ϼ�	0	1	2	3	4	5	6
//���� ���� �� ���� �巡�� ��	0	0	0	0	0	0	1
//���� ���� �� �ִ� �巡�� ��	0	0	1	1	2	3	4
//�巡�� �� ��	1	1	1	2	3	5	7
//0��~1��: �巡�� ���� �ϳ� �ֽ��ϴ�.
//2�� : �ʱ� �巡���� ��ȭ��, ���� �ϳ� ���ҽ��ϴ�.���� �巡�� ���� �巡�� �� ���� ���� 2�Դϴ�.
//3�� : �ʱ� �巡���� �� �� �� ���� ���ҽ��ϴ�.���� �巡�� ���� �巡�� �� ���� ���� 3�Դϴ�.
//4�� : ��Ʋ ���� ���� �巡�� ���� ��ȭ�߽��ϴ�.��ȭ�� �巡��� �ʱ� �巡���� ���� �ϳ��� ���ҽ��ϴ�.���� �巡�� ���� �巡�� �� ���� ���� 5�Դϴ�.
//���� 6�� �� �巡��� �巡�� ���� �� 12���� �˴ϴ�.