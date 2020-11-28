#include <iostream>

/// <summary>
/// Propagate the rightmost set bit.
/// 01010000 -> 01011111
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
unsigned long propagate_right(unsigned long x)
{
	return x | (x - 1);
}

int main(void)
{
	std::cout<<propagate_right(44);
	return 0;
}