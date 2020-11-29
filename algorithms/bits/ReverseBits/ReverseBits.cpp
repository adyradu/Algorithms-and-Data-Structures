#include <iostream>
#include <vector>

/// <summary>
/// Reverse the bits in an integer.
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
template<typename T>
T reverse_bits(T x) {
    T result = 0;
    int i = 0;
    constexpr int width = sizeof(T) * 8;

    while (i < width)
    {
        result = (result << 1) | (x & 1);
        x = x >> 1;
        ++i;
    }

    return result;
}

/// <summary>
/// Cache a number of revert bits results.
/// </summary>
/// <param name="cache"></param>
/// <param name="size"></param>
void build_cache(std::vector<unsigned short>& cache, unsigned long long size)
{
    for (unsigned long long i = 0; i < size; ++i)
    {
        cache[i] = reverse_bits<unsigned short>(static_cast<unsigned short>(i));
    }
}

/// <summary>
/// Stitch the revert of a 64 bit integer using cached 16 bits parts.
/// </summary>
/// <param name="x"></param>
/// <param name="cache"></param>
/// <returns></returns>
unsigned long long reverse_bits_cache(unsigned long long x, const std::vector<unsigned short>& cache)
{
    unsigned long long p1 = (static_cast<unsigned long long>(cache[x & 0xFFFF]) << 48);
    unsigned long long p2 = (static_cast<unsigned long long>(cache[(x >> 16) & 0xFFFF]) << 32);
    unsigned long long p3 = (static_cast<unsigned long long>(cache[(x >> 32) & 0xFFFF]) << 16);
    unsigned long long p4 = (static_cast<unsigned long long>(cache[(x >> 48) & 0xFFFF]));
    return p1 | p2 | p3 | p4;
}

int main()
{
    constexpr unsigned long long cache_size = 65536;
    std::vector<unsigned short> cache(cache_size);
    build_cache(cache, cache_size);
    bool success = true;

    for (unsigned long long i = 0; i < 1000000ULL; ++i)
    {
        unsigned long long r1 = reverse_bits(i);
        unsigned long long r2 = reverse_bits_cache(i, cache);

        if (r1 != r2)
        {
            std::cout << "Failed " << i << std::endl;
            success = false;
            break;
        }
    }

    if (success)
    {
        std::cout << "Success" << std::endl;
    }

	return 0;
}