#include <iostream>

/** �˻ʺ����� */

using namespace std;

const int AreaSize = 8;// �ʺ�ĸ��������� AreaSize * AreaSize������
int num = 0;

void Solve(bool arr[AreaSize][AreaSize], int row);
bool Check(bool arr[AreaSize][AreaSize], int row, int column);
void output(bool arr[AreaSize][AreaSize]);

//row ��  column ��
/** ���ݷ� */
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
				Solve(arr, row + 1); // β���ݹ�ķ�ʽ
			}
		}
		arr[row][column] = false;
	}
}

//�ж���ŵ��Ƿ�Ϲ�
bool Check(bool arr[AreaSize][AreaSize], int row, int column)
{
	//����ǵ�һ�У�Ϊtrue	
	if (row == 0)
	{
		return true;
	}

	//�ж�����
	int i, j;
	for (i = 0; i < row; ++i)
	{
		if (arr[i][column])
		{
			return false;
		}
	}

	//�ж���б��
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

	//�жϸ�б��
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
