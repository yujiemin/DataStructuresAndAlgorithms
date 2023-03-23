
#include <iostream>
#include <vector>

/** 数量 */
const int NUMS = 4;
/** 数组存储最大个数 */
const int COUNTS = 100;

using namespace std;

int main41()
{
	/** 要输入的数字个数 */
	int N;
	int NumArr[COUNTS + 1] = { 0 };
	int Counts[NUMS] = { 0 };
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> NumArr[i];
		Counts[NumArr[i]]++;
	}

	for (int i = 1; i <= N ; ++i)
	{
		std::cout << NumArr[i] << " ";
	}
	std::cout << std::endl;

	int SwapCount = 0;

	//j2是排序后2的起始位置， j3是排序后3的起始位置
	int j2 = Counts[1] + 1, j3 = Counts[1] + Counts[2] + 1;

	//第一轮中，将1范围内的2和2范围内的1， 还有1范围内的3和3范围内的1进行交换
	for (int i = 1; i <= Counts[1]; ++i)
	{
		//1区间的2 和 2区间的1 交换
		if (NumArr[i] == 2)
		{
			while (j2 <= Counts[1] + Counts[2] && NumArr[j2] != 1)
			{
				j2++;
			}

			if (j2 <= Counts[1] + Counts[2])
			{
				int Temp = NumArr[j2];
				NumArr[j2] = NumArr[i];
				NumArr[i] = Temp;

				SwapCount++;
			}
		}

		//1区间的3和3区间的1交换
		if (NumArr[i] == 3)
		{
			while (j3 <= N && NumArr[j3] != 1)
			{
				j3++;
			}
			if (j3 <= N)
			{
				int Temp = NumArr[j3];
				NumArr[j3] = NumArr[i];
				NumArr[i] = Temp;

				SwapCount++;
			}
		}
	}

	//第二轮中就把1区间中不属于1的替换掉，
	j2 = Counts[1] + 1;
	for(int i = 1; i <= Counts[1]; ++i)
	{
		if (NumArr[i] != 1)
		{
			while (j2 <= N && NumArr[j2] != 1)
			{
				j2++;
			}

			if (j2 <= N)
			{
				int Temp = NumArr[j2];
				NumArr[j2] = NumArr[i];
				NumArr[i] = Temp;

				SwapCount++;
			}
		}
	}

	//第四轮就交换2区间的3和3区间的2交换
	j3 = Counts[1] + Counts[2] + 1;
	for (int i = Counts[1] + 1; i <= Counts[1] + Counts[2]; ++i)
	{
		if (NumArr[i] != 2)
		{
			while (j3 <= N && NumArr[j3] != 2)
			{
				j3++;
			}

			if (j3 <= N)
			{
				int Temp = NumArr[j3];
				NumArr[j3] = NumArr[i];
				NumArr[i] = Temp;
				SwapCount++;
			}
		}
	}

	std::cout << "一共交换的次数是:" << SwapCount << std::endl;

	for (int i = 1; i <= N; ++i)
	{
		std::cout << NumArr[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}