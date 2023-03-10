#include <iostream>

using namespace std;


void ReverseChar()
{
	char ch;
	cin.get(ch);

	if (ch != '\n')
	{
		ReverseChar();
		cout.put(ch);
	}
}

/** ì³²¨ÄÇÆõÊıÁĞ */
int Fib(int n)
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main1()
{
	//ReverseChar();

	for (int i = 0; i < 20; ++i)
	{
		std::cout << Fib(i) << std::endl;
	}

	return 0;
}