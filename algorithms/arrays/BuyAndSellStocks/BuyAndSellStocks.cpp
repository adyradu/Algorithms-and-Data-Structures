#include<iostream>
#include<vector>

/// <summary>
/// Return the total profit from buying and selling a stock once over
/// a period of time. The input is an array of stock prices
/// in a particular day. Only one transaction is allowed per day.
/// The idea is to iterate the array and maintain the minimum value
/// we have seen so far. Then, we compute the partial gain by subtracting
/// the minimum seen so far from the current value.
/// 
/// Time complexity: O(n), space complexity: O(1).
/// </summary>
/// <param name="prices"></param>
/// <returns></returns>
double BuyAndSellStockOnce(const std::vector<double>& prices) {
    if (!prices.size())
    {
        return 0.0;
    }

    double minBuy = prices[0];
    double maxGain = 0;

    for (int i = 1; i < prices.size(); ++i)
    {
        maxGain = std::max(maxGain, prices[i] - minBuy);
        minBuy = std::min(minBuy, prices[i]);
    }

    return maxGain;
}

/// <summary>
/// Return the total profit from buying and selling a stock up to
/// two times over a period of time. The input is an array of stock prices
/// in a particular day. Only one transaction is allowed per day.
/// 
/// The idea is to make a pass over the array and compute max
/// profit that can be made by a single buy and sell up to day i.
/// We make another pass backwards to compute the max profit that
/// can be made by a single buy and sell between day i + 1 and size(array).
/// If F, B are the arrays that hold the partial results for forward and
/// backward iteration, the total result would be max(F[i], B[i] + F[i - 1]).
/// 
/// Time complexity: O(n) and space complexity O(n).
/// </summary>
/// <param name="prices"></param>
/// <returns></returns>
double BuyAndSellStockTwice(const std::vector<double>& prices) {
    std::vector<double> f = std::vector<double>(prices.size(), 0);
    double max_total_profit = 0;
    double min_price_so_far = std::numeric_limits<double>::max();

    for (size_t i = 0; i < prices.size(); ++i)
    {
        min_price_so_far = std::min(min_price_so_far, prices[i]);
        max_total_profit = std::max(max_total_profit, prices[i] - min_price_so_far);
        f[i] = max_total_profit;
    }

    double max_price_so_far = std::numeric_limits<double>::min();

    for (size_t i = prices.size() - 1; i > 0; --i)
    {
        max_price_so_far = std::max(max_price_so_far, prices[i]);
        max_total_profit = std::max(max_total_profit, max_price_so_far - prices[i] + f[i - 1]);
    }

    return max_total_profit;
}

int main(void)
{
	return 0;
}