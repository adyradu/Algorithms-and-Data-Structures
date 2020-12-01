#include<iostream>

/// <summary>
/// Reverse an integer.
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
long long reverse(int x)
{
    long long res = 0;
    int aux = x;
    aux = aux < 0 ? -aux : aux;

    while (aux)
    {
        res = res * 10 + (aux % 10);
        aux /= 10;
    }

    return x < 0 ? -res : res;
}

int main()
{
    std::cout << reverse(-34);
    return 0;
}