#include <iostream>
#include <vector>
using namespace std;

int main1()
{
	int N;
	int K = 0;
	vector<int> ChildN;
	while (cin >> N)
	{
		ChildN.clear();
		if (N <= 4)
		{
			ChildN.push_back(1);
			ChildN.push_back(N-1);
		}
		else
		{
			/** 拆分的数 */
			int M = 2;
			/** 余数 */
			int K = N;
			for (; K >= M; ++M)
			{
				ChildN.push_back(M);
				K -= M;
			}
			//如果最后一个数等于余数，则要先加上一个1，因为数字是从2开始的。
			if (K == ChildN.back())
			{
				ChildN.back() += 1;
			}

			//元素从后往前加1
			for (int i = ChildN.size() - 1; i >= 0 && K > 0; --i, --K)
			{
				ChildN[i] += 1;
			}
		}


		for (int Element : ChildN)
		{
			cout << Element << " ";
		}

		cout << endl;

		int Times = 1;
		for (int Element : ChildN)
		{
			Times *= Element;
		}

		cout << "最后的乘积是：" << Times << endl;
	}

	system("pause");

	return 0;
}