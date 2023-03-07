#pragma once

/** ������� */

#include "VectorStack.h"
#include <string>

class BigInteger
{
public:
	BigInteger(const std::string& strInteger);

	/** ����+������ */
	BigInteger& operator+(BigInteger& bigInt);

	/** ��ӡ */
	void Display();

private:
	/** �洢���ֵ����� */
	VStack<int> m_digit;

	/** �Ƿ��н��� */
	bool bCarry;
};

