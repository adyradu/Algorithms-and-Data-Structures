#include <iostream>

/// <summary>
/// Revers a non-negative integer.
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
unsigned int reverse_positive(unsigned int num)
{
	unsigned int result = 0;

	while (num)
	{
		result = result * 10 + num % 10;
		num /= 10;
	}

	return result;
}

/// <summary>
/// Tests whether an integer is a palindrome.
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
bool is_palindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	return reverse_positive(static_cast<unsigned int>(x)) == x;
}

int main()
{
	std::cout << is_palindrome(231132);
	return 0;
}