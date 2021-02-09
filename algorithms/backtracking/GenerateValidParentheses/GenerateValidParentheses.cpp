#include <vector>
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// It generates all strings formed by valid parentheses. It accumulates the result.
/// </summary>
/// <param name="num_parens_left">Number of left parentheses in the solution string.</param>
/// <param name="num_parens_right">Number of right parentheses in the solution string.</param>
/// <param name="sol">current solution string.</param>
/// <param name="result">Vector holding all strings.</param>
void GenerateBalancedParenthesesAcc(int num_parens_left, int num_parens_right, string sol, vector<string>* result)
{
    // If we matched all left parentheses add the solution to the result.
    //
    if (!num_parens_right)
    {
        result->emplace_back(sol);
        return;
    }

    // Add a left parentheses if we still can.
    //
    if (num_parens_left > 0)
    {
        GenerateBalancedParenthesesAcc(num_parens_left - 1,
            num_parens_right,
            sol + "(",
            result);
    }

    // If there are more left parentheses add one right parenthesis to match.
    //
    if (num_parens_left < num_parens_right)
    {
        GenerateBalancedParenthesesAcc(num_parens_left,
            num_parens_right - 1,
            sol + ")",
            result);
    }
}

/// <summary>
/// Generate all string formed with balanced parentheses with the number of
/// parentheses pairs equal to num_pairs.
/// </summary>
/// <param name="num_pairs">Number of parantheses pairs.</param>
/// <returns>All valid strings formed by balanced parentheses.</returns>
vector<string> GenerateBalancedParentheses(int num_pairs) {
    vector<string> result;
    GenerateBalancedParenthesesAcc(num_pairs, num_pairs, "", &result);
    return result;
}

int main()
{
    std::cout << "num_pairs = 5" << endl;
    vector<string> res5 = GenerateBalancedParentheses(5);
    for (string str : res5)
    {
        std::cout<<str<<" ";
    }

    std::cout << endl;

    std::cout << "num_pairs = 1" << endl;
    vector<string> res1 = GenerateBalancedParentheses(1);
    for (string str : res1)
    {
        std::cout << str << " ";
    }

    std::cout << endl;

    std::cout << "num_pairs = 0" << endl;
    vector<string> res0 = GenerateBalancedParentheses(0);
    for (string str : res0)
    {
        std::cout << str << " ";
    }

    return 0;
}