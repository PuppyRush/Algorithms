#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		int maximum;
		char buf[31];
		scanf("%d %s", &maximum, buf);
		string str(buf);

		int64_t doubled = 1ull;
		int64_t damaged = 0;

		for each(auto c in str)
		{
			switch (c)
			{
			case 'C':
				doubled *= 2ull;
				break;
			case 'S':
				damaged += doubled;
				break;
			}
		}

		const size_t len = str.size();
		int64_t cnt = -1;
		int64_t i = str.size() - 2;
		while (maximum < damaged && i >= 0)
		{
			if (str.at(i) == 'C')
			{
				size_t s_cnt = 0;
				int t = i + 1;
				for (; t < len && str[t] != 'C'; t++)
				{

					s_cnt++;
				}
				if (s_cnt>0)
				{
					doubled /= 2;
					swap(str.at(i), str.at(t - 1));
					cnt += s_cnt;
					damaged -= doubled*s_cnt;
					s_cnt = 0;
				}
			}
			i--;
		}

		if (cnt >= 0 || maximum >= damaged)
			std::cout << "Case #" << (l + 1) << ": " << cnt + 1 << "\n";
		else
			std::cout << "Case #" << (l + 1) << ": IMPOSSIBLE\n";
	}

	return 0;
}
