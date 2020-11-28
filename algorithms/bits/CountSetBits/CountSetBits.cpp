#include<iostream>

/// <summary>
/// Counts the number of set bits for a given value.
/// Bitwise AND between a number x and x - 1 clears the least significant
/// set bit. Here is an example:
/// x = 12 (1100)
/// x - 1 = 11 (1011)
/// x & (x - 1) = 1000.
/// Time complexity is O(k) where k is the number of bits set.
/// </summary>
/// <typeparam name="T">Type of the value.</typeparam>
/// <param name="x">The input value.</param>
/// <returns>The number of set bits.</returns>
template<typename T>
short count_set_bits(T x)
{
	short count = 0;

	while (x)
	{
		x &= (x - 1);
		++count;
	}

	return count;
}

int main(void)
{
	std::cout << count_set_bits(0) << std::endl;

	return 0;
}