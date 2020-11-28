#include <iostream>

/// <summary>
/// Calculates x mod pow2 where pow2 is a power of two.
/// </summary>
/// <param name="x"></param>
/// <param name="pow2"></param>
/// <returns></returns>
unsigned long mod_pow_two(unsigned long x, unsigned long pow2)
{
	return x & (pow2 - 1);
}

/// <summary>
/// Checks if a number is a power of two.
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
bool is_pow_two(unsigned long x)
{
	return !(x & x - 1);
}

int main(void)
{
	std::cout << is_pow_two(64) << std::endl;
	std::cout << mod_pow_two(77, 64);
	return 0;
}