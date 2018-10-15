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
//���� ����
//���ӿ� ������ ��� �������� �������� �����ϴ� �⼮ �̺�Ʈ�� k�� ���� �����Ϸ� �մϴ�.��¥�� ���� ������ ���� �־��� ��, k�� ���� ���� ������ ���� ���� �ִ밡 �ǵ��� �̺�Ʈ �Ⱓ�� ���Ϸ� �մϴ�.
//
//��¥�� ���� ������ ���� ������� ��� �迭 estimates�� �⼮ �̺�Ʈ�� �����ϴ� �Ⱓ k�� �Ű������� �־����ϴ�.k�� ���� ���� ������ ���� ���� �ִ밡 �ǵ��� �̺�Ʈ �Ⱓ�� ������ ��, �� ���� ���� ������ �� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.
//
//���� ����
//estimates�� ���̰� 1 �̻� 200, 000 ������ �迭�Դϴ�.
//estimates�� ���Ҵ� 10, 000 ������ �ڿ����Դϴ�.
//k�� 1 �̻� 100, 000 �����̰�, estimates�� ���̺��� �۰ų� �����ϴ�.
//����� ��
//estimates	k	return
//[1, 1, 9, 3, 7, 6, 5, 10]	4	28
//[1, 1, 5, 1, 1]	1	5
//���� ����
//���� #1
//�⼮ �̺�Ʈ�� 4�ϰ� ������ �մϴ�. 4�ϰ� ���� ������ ���� ���� �ִ밡 �Ǵ� ����[7, 6, 5, 10]�Դϴ�.���� 28�� return �ϸ� �˴ϴ�.
//
//���� #2
//�⼮ �̺�Ʈ�� �Ϸ� ������ �մϴ�. 1�ϰ� ���� ������ ���� ���� �ִ밡 �Ǵ� ����[5]�Դϴ�.���� �ִ� 5�� return �ϸ� �˴ϴ�.