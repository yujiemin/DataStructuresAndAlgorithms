#include <iostream>
#include <vector>
using namespace std;

/** 分段函数 */
int Segmentation(vector<int>& NumArr, int T, int N, int M)
{
	int Count = 0;
	int Res = 0;

	for (int i = 0; i < N; ++i)
	{
		if (NumArr[i] > T)
		{
			return INT_MAX;
		}

		if (Count + NumArr[i] <= T)
		{
			Count += NumArr[i];
		}
		else
		{
			Count = NumArr[i];
			Res += 1;
			if (Res > M)
			{
				break;
			}
		}
	}

	return  Res + 1;
}

/**
 * 给出一个长度为N的正整数数列，现在要把它分成K段，
 * 且每一段里所有数字的和都不超过 T, 问 T 的最小值是多少？
 */
int main()
{
	/** 长度为N的正整数数列 */
	int N;
	/** 需要的分段 */
	int M;

	cin >> N >> M;

	int Sum = 0;
	vector<int> NumArr;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		NumArr.push_back(Temp);
		Sum += Temp;//计算数字之和
	}

	/** 下界 : 数列和/段数*/
	int Low = Sum / M;
	/** 上界 : 所有数字的和 */
	int Upper = Sum;

	while (Low < Upper)
	{
		int T = (Low + Upper) / 2;
		//如果每段和不超过T的情况下，数列可分为小于等于M段，则说明T高了，需要往左半边继续找
		if (Segmentation(NumArr, T, N, M) <= M)
		{
			Upper = T;
		}
		else //否则t不够大，需要往右半边继续
		{
			Low = T + 1;
		}
	}

	std::cout << "T 的最小值是：" << Low << std::endl;

	system("pause");
	return 0;
}