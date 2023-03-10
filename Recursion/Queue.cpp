#include <iostream>

/** 八皇后问题 */

using namespace std;

const int AreaSize = 8;// 皇后的个数，或者 AreaSize * AreaSize的网格
int num = 0;

void Solve(bool arr[AreaSize][AreaSize], int row);
bool Check(bool arr[AreaSize][AreaSize], int row, int column);
void output(bool arr[AreaSize][AreaSize]);

//row 行  column 列
/** 回溯法 */
void Solve(bool arr[AreaSize][AreaSize], int row)
{
	int column = 0;
	for (column = 0; column < AreaSize;  ++column)
	{
		arr[row][column] = true;
		if (Check(arr, row, column))
		{
			if (row + 1 == AreaSize)
			{
				output(arr);
			}
			else
			{
				Solve(arr, row + 1); // 尾部递归的方式
			}
		}
		arr[row][column] = false;
	}
}

//判断落脚点是否合规
bool Check(bool arr[AreaSize][AreaSize], int row, int column)
{
	//如果是第一行，为true	
	if (row == 0)
	{
		return true;
	}

	//判断纵向
	int i, j;
	for (i = 0; i < row; ++i)
	{
		if (arr[i][column])
		{
			return false;
		}
	}

	//判断正斜向
	i = row - 1;
	j = column - 1;

	while (i >= 0 && j >= 0)
	{
		if (arr[i][j])
		{
			return false;
		}
		i--;
		j--;
	}

	//判断负斜向
	i = row - 1;
	j = column + 1;

	while (i >= 0 && j < AreaSize)
	{
		if (arr[i][j])
		{
			return false;
		}
		i--;
		j++;
	}

	return true;
}

void output(bool arr[AreaSize][AreaSize])
{
	num++;
	cout << "============" << num << "==============" << endl;

	for (int i = 0; i < AreaSize; ++i)
	{
		for (int j = 0; j < AreaSize; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "=============================" << endl;
 }

int main()
{
	bool chessboard[8][8] = { false };

	Solve(chessboard, 0);

	system("pause");
	return 0;
}
