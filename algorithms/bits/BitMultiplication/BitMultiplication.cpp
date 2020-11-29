// BitMultiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

/// <summary>
/// Addition using only bitwise operators.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
unsigned long long Addition(unsigned long long x, unsigned long long y) {
    unsigned long long result = 0;
    unsigned long long bitMask = 0x1;
    unsigned long long carryOver = 0;

    if (x == 0) {
        return y;
    }
    else if (y == 0) {
        return x;
    }

    while (bitMask)
    {
        unsigned long long cx = (x & bitMask);
        unsigned long long cy = (y & bitMask);
        result ^= cx ^ cy ^ carryOver;
        carryOver = ((cx & cy) | (cx & carryOver) | (cy & carryOver));

        carryOver = carryOver << 1;
        bitMask = bitMask << 1;
    }

    return result;
}

/// <summary>
/// Multiplication using only bitwise operators.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
    unsigned long long bitMask = 0x1;
    unsigned long result = 0;
    unsigned long long shiftedY = y;

    while (bitMask)
    {
        if (x & bitMask) {
            result = Addition(result, shiftedY);
        }

        shiftedY = shiftedY << 1;
        bitMask = bitMask << 1;
    }

    return result;
}

int main()
{
    std::cout << Multiply(3456, 9844);
}
