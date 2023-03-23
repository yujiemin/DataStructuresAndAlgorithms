#include <iostream>
using namespace std;

int main()
{
	/** N个星期 */
	int N;
	/** 保养费 */
	int S;
	cin >> N >> S;
	/** 总费用 */
	int Total = 0;

	/** 每周每台的成本价 */
	int C;
	/** 每周交付的台数 */
	int Y;

	int MinC = INT_MAX - S;

	for (int i = 0; i < N; ++i)
	{
		cin >> C >> Y;
		MinC = MinC + S;
		if (C < MinC)
		{
			MinC = C;
		}

		Total += MinC * Y;
	}

	cout << Total << endl;

	system("pause");
	return 0;
}






















int main1()
{
	/* N周时间内完成订单*/
	int N;
	/* 每周的保养费 */
	int S;
	/* 第i周生产一台机器的成本*/
	int C;

	std::cin >> N >> S;

	/* 第i周要交付的机器数两*/
	int Y;
	/* 最小费用 */
	int MinC = INT_MAX - S;
	/* 总费用 */
	int Total = 0;

	for (int i = 0; i < N; ++i)
	{
		// 读入第i周的生产一台的花费C，以及要交付的机器台数Y
		cin >> C >> Y;

		// 上一周的最第低价格加上储藏一周的费用，得到利用之前库存的最低价格
		MinC = MinC + S;
		// 如果这周生产一台的价格比利用之前库存的价格低，就全部由这周生产
		if (C < MinC)
		{
			MinC = C;
		}
		// 计算交付本周所有机器的最低价格，并且累加
		Total += Y * MinC;
	}

	std::cout << Total << std::endl;

	system("pause");
	return 0;
}