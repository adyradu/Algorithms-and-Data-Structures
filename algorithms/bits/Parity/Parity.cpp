#include <iostream>
#include <vector>

/// <summary>
/// The function returns the parity of an integer.
/// Parity is defined as 1 if the number of set bits is odd
/// and 0 otherwise.
/// 
/// Parity of a number x can be calculated as xor of all its bits.
/// For example if x = 11 (1011), 1 xor 0 xor 1 xor 1 = 1. We call
/// Xor(x) xor of all its bits.
/// Given that xor operation is associative and commutative, we can
/// calculate Xor(x) as Xor(first_half_of(x)) xor Xor(second_half_of(x)).
/// The complexity of this is O(log(n)) where n is the width of x.
/// </summary>
/// <param name="x"></param>
/// <returns>Returns the parity.</returns>
short parity(unsigned long long x)
{
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;

	return x & 0x1;
}

/// <summary>
/// Parity for unsigned short.
/// </summary>
/// <param name="x"></param>
/// <returns>Returns the parity.</returns>
short parity(unsigned short x)
{
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;

	return x & 0x1;
}

void build_cache(std::vector<unsigned short>& cache)
{
	constexpr unsigned short max_short = std::numeric_limits<unsigned short>::max();
	for (unsigned short i = 0; i < max_short; ++i)
	{
		cache[i] = parity(i);
	}
}

/// <summary>
/// Computes parity of a number using the caching method.
/// We pre-compute parity of the 2^16 integers and then compute
/// the parity of a 64 bit integer by taking the xor of all
/// components.
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
short parity_caching(unsigned long long x, const  std::vector<unsigned short>& cache)
{
	unsigned short mask = 0xFFFF;

	return cache[x >> 48] ^
		cache[x >> 32 & mask] ^
		cache[x >> 16 & mask] ^
		cache[x & mask];
}

int main(void)
{
	bool pass = true;
	std::vector<unsigned short> cache(std::numeric_limits<unsigned short>::max() + 1);
	build_cache(cache);

	for (unsigned long long x = 0; x < 1000000; ++x)
	{
		short p1 = parity((unsigned long long)(x));
		short p2 = parity_caching(x, cache);

		if (p1 != p2)
		{
			std::cout << x << std::endl;
			pass = false;
			break;
		}
	}

	std::cout << (pass ? "Success" : "Failure") << std::endl;

	return 0;
}