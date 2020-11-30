#include<iostream>

/// <summary>
/// Return the quotent of the division of two non-negative integers.
/// Every iteration it calculates max k such that 2^k*y < x. Once a k
/// is found we subtract 2^k*y from x.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int divide(int x, int y) {
    unsigned short p = 32;
    unsigned long long pow_y = static_cast<unsigned long long>(y) << p;
    int result = 0;

    while (x >= y)
    {
        while (pow_y > x)
        {
            pow_y >>= 1;
            --p;
        }

        x = x - pow_y;
        result += 1 << p;
    }

    return result;
}

int main()
{
    std::cout << divide(65, 4) << std::endl;
	return 0;
}