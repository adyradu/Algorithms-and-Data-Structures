#include <iostream>

/// <summary>
/// Calculates x^y.
/// It takes advantage of x ^ y = x ^ (y/2) * x ^ (y/2).
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
double power(double x, int y) {
    if (y < 0) {
        y = -y;
        x = 1 / x;
    }

    if (y == 0) {
        return 1;
    }

    if (y & 0x1) {
        return x * power(x, y - 1);
    }

    return power(x, y / 2) * power(x, y / 2);
}

/// <summary>
/// Calculates x^y iteratively.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
double power_iterative(double x, int y) {
    if (y < 0) {
        y = -y;
        x = 1 / x;
    }

    double res = 1;

    while (y)
    {
        if (y & 0x1) {
            res *= x;
        }

        x *= x;
        y >>= 1;
    }

    return res;
}

int main()
{
    std::cout << power(10, 3);
	return 0;
}