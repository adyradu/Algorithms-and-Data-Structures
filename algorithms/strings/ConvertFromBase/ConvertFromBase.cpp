#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Convert an integer (base 10) into base b.
/// </summary>
/// <param name="a">The input integer in base 10.</param>
/// <param name="b">The base.</param>
/// <returns>A string representing the number in base b.</returns>
string ConstructFromBase(int a, int b)
{
    string res;
    int sign = a < 0 ? (-1) : 1;

    if (sign == -1)
    {
        a *= (-1);
    }

    while (a)
    {
        int nextDigit = a % b;
        char nextDigitChar = nextDigit < 10 ? '0' + nextDigit
            : ('A' + nextDigit - 10);
        res.push_back(nextDigitChar);
        a = a / b;
    }

    if (sign == -1)
    {
        res.push_back('-');
    }

    reverse(res.begin(), res.end());

    if (!res.size())
    {
        res.push_back('0');
    }

    return res;
}

/// <summary>
/// Convert a integer from base b to base 10.
/// </summary>
/// <param name="num_as_string">Input number as string.</param>
/// <param name="b">The base to convert to.</param>
/// <returns>The result base.</returns>
int ConvertToInt10(const string& num_as_string, int b)
{
    int res = 0;
    int start = (num_as_string[0] == '+' || num_as_string[0] == '-') ?
        1 : 0;

    for (int i = start; i < num_as_string.size(); ++i)
    {
        res = res * b + (num_as_string[i] > '9' ? (num_as_string[i] - 'A' + 10) : (num_as_string[i] - '0'));
    }

    if (num_as_string[0] == '-')
    {
        return (-1) * res;
    }

    return res;
}

/// <summary>
/// Convert a number from base b1 to base b2.
/// </summary>
/// <param name="num_as_string">Input number as string.</param>
/// <param name="b1">From base</param>
/// <param name="b2">To base</param>
/// <returns>The result represented as string.</returns>
string ConvertBase(const string& num_as_string, int b1, int b2) {
    return ConstructFromBase(ConvertToInt10(num_as_string, b1), b2);
}

int main()
{
    cout << ConvertBase("12345", 10, 6) << endl;

	return 0;
}