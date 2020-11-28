#include <iostream>

/// <summary>
/// Swap two bits in a give number.
/// First, we check if the bits differ. If so, 
/// we flip them using xor operator.
/// </summary>
/// <param name="x"></param>
/// <param name="i"></param>
/// <param name="j"></param>
/// <returns></returns>
long long swap_bits(long long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        long long bitMask = (1LL << i) | (1LL << j);
        x ^= bitMask;
    }

    return x;
}

int main(void)
{
    std::cout << swap_bits(73, 6, 1) << std::endl;
    return 0;
}