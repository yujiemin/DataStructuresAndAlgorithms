#pragma once

/** 大的整型 */

#include "VectorStack.h"
#include <string>

class BigInteger
{
public:
	BigInteger(const std::string& strInteger);

	/** 重载+操作符 */
	BigInteger& operator+(BigInteger& bigInt);

	/** 打印 */
	void Display();

private:
	/** 存储数字的数组 */
	VStack<int> m_digit;

	/** 是否有进制 */
	bool bCarry;
};

