
#include <iostream>
#include <vector>

/** 跑步速度：17m/s
 *	原地休息1s恢复魔法4点
 *	闪现1S内移动 60m/s
 */

/** 第一种解法： */
int main_031()
{
	/** 初始的魔法值 */
	int M;
	/** 岛与出口的距离 S */
	int S;
	/** 岛沉默的时间T */
	int T;


	std::cin >>  M >> S >> T;

	int MoveDis = 0;
	for (int i = 1; i <= T && MoveDis < S; ++i)
	{
		if (M > 10)
		{
			MoveDis += 60;
			M -= 10;
		}
		else if (M < 2 && (T-i < 6 || S-MoveDis < 102)
		      || M < 6 && (T-i < 2 || S-MoveDis < 34)
		      || M < 10 && (T-i < 1 || S-MoveDis < 17))
		{
			MoveDis += 17;
		}
		else
		{
			M += 4;
		}
	}


	if (MoveDis >= S)
	{
		std::cout << "逃出荒岛，移动总距离为：" << MoveDis << std::endl;
	}
	else
	{
		std::cout << "没有逃出荒岛，移动总距离为：" << MoveDis << std::endl;
	}

	system("pause");

	return 0;
}

/** 第二种解法：纯贪心 */
int main32()
{
	/** 初始的魔法值 */
	int M;
	/** 岛与出口的距离 S */
	int S;
	/** 岛沉默的时间T */
	int T;

	std::cin >> M >> S >> T;
	std::vector<int> disVector(T+1, 0);

	for (int i = 1; i <= T; ++i)
	{
		if (M >= 10)
		{
			M -= 10;
			disVector[i] = disVector[i - 1] + 60;
		}
		else
		{
			M += 4;
			disVector[i] = disVector[i - 1];
		}
	}

	for (int i = 1; i <= T; ++i)
	{
		disVector[i] = std::max(disVector[i], disVector[i - 1] + 17);
	}

	if (disVector[T] >= S)
	{
		std::cout << "逃出岛屿成功" << std::endl;
	}
	else
	{
		std::cout << "逃出岛屿失败，逃出距离：" << disVector[T] << std::endl;
	}

	system("pause");


	return 0;
}