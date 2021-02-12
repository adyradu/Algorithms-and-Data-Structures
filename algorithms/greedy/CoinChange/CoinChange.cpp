#include<iostream>
#include<array>

using namespace std;

/// <summary>
/// Given a set of coins with values 1, 5, 10, 25, 50, 100 and a change
/// find out the minimum number of coins that sum up to the change.
/// Solution:
/// Greedy Algorithm: Every time choose the highest coin that is less than
/// the remaining change. Note that this solution works only for this set of
/// coins. In the general case, this problem si NP complete.
/// </summary>
/// <param name="cents">The change.</param>
/// <returns></returns>
int coin_change_us(int cents)
{
    const std::array<int, 6> coins = { 100, 50, 25, 10, 5, 1 };
    int no_coins = 0;


    for (int i = 0; i < size(coins);)
    {
        if (coins[i] > cents)
        {
            ++i;
        }
        else
        {
            cents -= coins[i];
            ++no_coins;
        }
    }

    return no_coins;
}

int main()
{
    for (int i = 0; i <= 2000; ++i)
    {
        cout << coin_change_us(i) << endl;
    }

	return 0;
}