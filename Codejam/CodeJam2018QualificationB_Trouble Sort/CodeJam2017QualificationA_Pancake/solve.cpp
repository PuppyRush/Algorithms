#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator int_it;

int_it swap(const int_it left, const int_it right, const int_it end)
{
	if (*left > *(left + 1) && *(right - 1) > *right)
		return  end;
	if (*left < *(left + 1) && *(right - 1) < *right)
	{
		swap(*left, *right);
		return end;
	}
	return left+1;
}


int_it solver(vector<int> &origin, const int_it left, const int_it right, const size_t len, const int_it end)
{
	switch (len)
	{
	case 3:
		return swap(left, right, end);
	case 2:
	case 1:
	case 0:
		_ASSERT(0);
	}

	if (4 <= len && len <= 9)
	{
		for (auto it = left; it < right - 2; it++)
		{
			auto res_it = swap(it, it + 2, end);
			if (res_it != end)
				return res_it;
		}
		return end;
	}

	size_t portion = len / 3;

	size_t first = len / 3;
	size_t second = first;
	size_t third = len - first - second;

	auto left_it = solver(origin, left, left+first-1, first, end);
	auto middle_it = solver(origin, left+first , left+first+second-1 , second, end);
	auto right_it = solver(origin, left+first+second, right, third, end);

	if (*(left+first-1) < *(left+first) )
		return left+first;
	else if (left_it != end)
		return left_it;

	if (*(left + first + second - 1) < *(left + first + second))
		return left + first + second ;
	else if (middle_it != end)
		return middle_it;

	if (right_it != end)
		return right_it;

	return end;
}



int main() {

	int casesize = 0;
	cin >> casesize;

	for (int i = 0; i < casesize; i++)
	{
		int len = 0;
		char buf[11];
		vector<int> ary;
		ary.reserve(len);

		cin >> len;

		for (int i = 0; i < len; i++)
		{
			int buf = 0;
			cin >> buf;
			ary.push_back(buf);
		}

		auto it = solver(ary, ary.begin(), ary.end() - 1, ary.size(), ary.end());
		if (it != ary.end())
			cout << "Case #" << (i + 1) << ": " << distance(ary.begin(), it) << endl;
		else
			cout << "Case #" << (i + 1) << ": OK" << endl;
	}

	return 0;

}