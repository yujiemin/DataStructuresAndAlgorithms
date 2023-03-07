#include "BigInteger.h"

BigInteger::BigInteger(const std::string& strInteger)
{
	bCarry = false;

	for (char ch : strInteger)
	{
		m_digit.Push(atoi(&ch));
	}
}

BigInteger& BigInteger::operator+(BigInteger& bigInt)
{

	VStack<int> tempStack;
	while (m_digit.GetLength() >0 || bigInt.m_digit.GetLength() > 0)
	{
		int value1 = m_digit.GetLength() > 0 ? m_digit.GetTopElement() : 0;
		int value2 = bigInt.m_digit.GetLength() > 0 ? bigInt.m_digit.GetTopElement() : 0;
		int addValue = value1 + value2 + bCarry;

		if (addValue / 10 > 0)
		{
			bCarry = true;
		}
		else
		{
			bCarry = false;
		}

		tempStack.Push(addValue % 10);

		m_digit.Pop();
		bigInt.m_digit.Pop();
	}

	tempStack.Display();

	return  *this;
	
}

void BigInteger::Display()
{
	m_digit.DisplayNum();
}
