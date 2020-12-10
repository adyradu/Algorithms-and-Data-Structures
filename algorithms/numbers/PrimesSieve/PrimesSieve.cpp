#include<iostream>
#include<vector>

/// <summary>
/// Returns an array of all primes.
/// Complexity O(n*sqrt(n)) = O(n ^ (3/2))
/// Space complexity O(1).
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
std::vector<int> GeneratePrimes(int n) {
    std::vector<int> primes;

    for (int i = 2; i <= n; ++i)
    {
        int j = 0;
        int sqrti = sqrt(i);
        bool isPrime = true;
        while (j < primes.size() && primes[j] <= sqrti)
        {
            if (i % primes[j++] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primes.emplace_back(i);
        }
    }

    return primes;
}

/// <summary>
/// As soon as we find a prime number we discard all numbers that are
/// multiple of the prime numner.
/// We maintain an auxiliary array to record if a row is not prime.
/// We can start from p^2 (where p is prime) to mark its multiples.
/// Time complexity: O(nloglogn). Space complexity is O(n).
/// We could reduce space complexity to O(n/2) if we discard even numbers.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
std::vector<int> PrimesSieve(int n)
{
    std::vector<int> result;
    if (n < 2)
    {
        return result;
    }

    std::vector<bool> primeTest(n - 1, true);

    for (int i = 2; i <= n; ++i)
    {
        if (primeTest[i - 2] == true)
        {
            result.emplace_back(i);

            if (i <= sqrt(n))
            {
                for (int j = i * i - 2; j < n - 1; j = j + i)
                {
                    primeTest[j] = false;
                }
            }
        }
    }

    return result;
}

int main(void)
{
    std::vector<int> primes = PrimesSieve(100000);

    for (auto p : primes)
    {
        std::cout << p << " ";
    }

	return 0;
}