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
//문제의 입력값은 각 언어의 표준입력(stdin) 함수를, 출력값은 표준출력(stdout) 함수를 사용해주세요.
//청소년 교통카드
//최초 잔액이 20, 000원인 청소년 교통카드가 있다.
//
//이 카드는 사용할 때마다 운임만큼 차감되는데, 운임은 이동한 거리에 따라 결정된다.
//
//기본운임
//
//40km까지 : 720원
//추가 운임
//
//41km부터 : 8km마다 80원 추가
//(예 : 48km까지 800원, 56km까지 880원)
//각각의 이동 거리를 입력하면 카드의 최종 잔액을 출력하는 프로그램을 작성하시오.
//
//유의사항
//최소 이동거리는 4km이며 최대 이동거리는 178km이다.이를 벗어나면 현재 잔액을 출력하고 프로그램을 종료한다.
//더 이상 차감할 수 없으면 이동할 수 없으므로 현재 잔액을 출력하고 프로그램을 종료한다.
//입력형식
//각 이동거리가 띄어쓰기로 구분되어 입력된다.예를 들어 8km를 이동한 후 다시 30km를 이동했다면 8 30이다.
//출력 형식
//카드에 남은 잔액을 출력한다.

//보기 입력 1
//11 128 15 111 59 31 70 102 50 172 88 56 40 41 12
//출력 1
//4160