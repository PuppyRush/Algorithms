//#include <iostream>
//// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
//#include <sstream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	string line;
//	getline(cin, line);
//	stringstream ss(line);
//	
//	int sum = 0;
//	int change = 20000;
//	for (int distance; !(ss >> distance).fail(); ) {
//
//		if (distance < 4 || distance >178)
//			break;
//
//		if (change < 720)
//			break;
//
//		change -= 720;
//		distance -= 40;
//
//		if (distance <= 0)
//			continue;
//		if (change < 0)
//			break;
//
//		int ch_dis = distance / 8;
//		if (distance % 8 == 0)
//			ch_dis--;
//
//		int exchange = change;
//		change -= (ch_dis + 1) * 80;
//
//		if (change < 0)
//		{
//			exchange %= 80;
//			change = exchange;
//			break;
//		}
//	}
//
//	cout << change;
//	return 0;
//}
//
//������ �Է°��� �� ����� ǥ���Է�(stdin) �Լ���, ��°��� ǥ�����(stdout) �Լ��� ������ּ���.
//û�ҳ� ����ī��
//���� �ܾ��� 20, 000���� û�ҳ� ����ī�尡 �ִ�.
//
//�� ī��� ����� ������ ���Ӹ�ŭ �����Ǵµ�, ������ �̵��� �Ÿ��� ���� �����ȴ�.
//
//�⺻����
//
//40km���� : 720��
//�߰� ����
//
//41km���� : 8km���� 80�� �߰�
//(�� : 48km���� 800��, 56km���� 880��)
//������ �̵� �Ÿ��� �Է��ϸ� ī���� ���� �ܾ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//���ǻ���
//�ּ� �̵��Ÿ��� 4km�̸� �ִ� �̵��Ÿ��� 178km�̴�.�̸� ����� ���� �ܾ��� ����ϰ� ���α׷��� �����Ѵ�.
//�� �̻� ������ �� ������ �̵��� �� �����Ƿ� ���� �ܾ��� ����ϰ� ���α׷��� �����Ѵ�.
//�Է�����
//�� �̵��Ÿ��� ����� ���еǾ� �Էµȴ�.���� ��� 8km�� �̵��� �� �ٽ� 30km�� �̵��ߴٸ� 8 30�̴�.
//��� ����
//ī�忡 ���� �ܾ��� ����Ѵ�.

//���� �Է� 1
//11 128 15 111 59 31 70 102 50 172 88 56 40 41 12
//��� 1
//4160