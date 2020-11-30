#include<iostream>

/// <summary>
/// Reverse an integer.
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
long long reverse(int x)
{
    long long res = 0;
    while (x)
    {
        res = res * 10 + (x % 10);
        x /= 10;
    }

    return res;
}

int main()
{
    std::cout << reverse(3478192);
    return 0;
}