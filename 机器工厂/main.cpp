#include <iostream>
using namespace std;

int main()
{
	/** N������ */
	int N;
	/** ������ */
	int S;
	cin >> N >> S;
	/** �ܷ��� */
	int Total = 0;

	/** ÿ��ÿ̨�ĳɱ��� */
	int C;
	/** ÿ�ܽ�����̨�� */
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
	/* N��ʱ������ɶ���*/
	int N;
	/* ÿ�ܵı����� */
	int S;
	/* ��i������һ̨�����ĳɱ�*/
	int C;

	std::cin >> N >> S;

	/* ��i��Ҫ�����Ļ�������*/
	int Y;
	/* ��С���� */
	int MinC = INT_MAX - S;
	/* �ܷ��� */
	int Total = 0;

	for (int i = 0; i < N; ++i)
	{
		// �����i�ܵ�����һ̨�Ļ���C���Լ�Ҫ�����Ļ���̨��Y
		cin >> C >> Y;

		// ��һ�ܵ���ڵͼ۸���ϴ���һ�ܵķ��ã��õ�����֮ǰ������ͼ۸�
		MinC = MinC + S;
		// �����������һ̨�ļ۸������֮ǰ���ļ۸�ͣ���ȫ������������
		if (C < MinC)
		{
			MinC = C;
		}
		// ���㽻���������л�������ͼ۸񣬲����ۼ�
		Total += Y * MinC;
	}

	std::cout << Total << std::endl;

	system("pause");
	return 0;
}