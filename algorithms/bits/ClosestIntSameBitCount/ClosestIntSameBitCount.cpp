#include <iostream>

/// <summary>
/// Find the closest integer with the same bit count.
/// The approach is to find the rightmost consecutive pair
/// of two bits that differ and swap them.
/// Time complexity is O(n) since we traverse the number, where
/// n is the width of the number.
///
/// </summary>
/// <param name="x">Input integer</param>
/// <returns>Closest integer</returns>
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
    short zeroPos = -2;
    short onePos = -2;
    unsigned long long aux = x;
    short cPos = 0;
    short width = sizeof(unsigned long long) * 8;

    while (cPos < width)
    {
        if (aux & 0x1)
        {
            onePos = cPos;
        }
        else
        {
            zeroPos = cPos;
        }

        if ((onePos == zeroPos + 1) || (zeroPos == onePos + 1))
        {
            break;
        }

        aux = aux >> 1;
        ++cPos;
    }

    // Swap 1 and 0 positions.
    //
    x = x & ~(1LL << onePos) | (1LL << zeroPos);

    return x;
}

int main()
{
    std::cout << ClosestIntSameBitCount(48) << std::endl;
    return 0;
}