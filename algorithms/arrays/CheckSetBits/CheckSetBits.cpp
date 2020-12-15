#include<iostream>

/// <summary>
/// Returns true if all bits are set in n and false otherwise.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
bool CheckSetBits(int n)
{
	return ((n + 1) & n) == 0;
}

int main()
{
	int n;

	std::cout << CheckSetBits(7);
}