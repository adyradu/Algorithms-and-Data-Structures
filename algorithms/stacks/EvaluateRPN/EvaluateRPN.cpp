#include <string>
#include <iostream>
#include <stack>

using namespace std;

int Calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '/':
        return a / b;
    case '*':
        return a * b;
    default:
        throw;
    }
}

int Evaluate(const string& expression) {
    stack<int> results;
    int cPos = 0;

    while (cPos < expression.size())
    {
        int nextPos = expression.find_first_of(',', cPos);
        string cStr = expression.substr(cPos, nextPos - cPos);

        if (isdigit(cStr[0]) || cStr.size() > 1)
        {
            results.push(stoi(cStr));
        }
        else
        {
            int rightOp = results.top(); results.pop();
            int leftOp = results.top(); results.pop();

            results.push(Calculate(leftOp, rightOp, cStr[0]));
        }

        cPos = nextPos == -1 ? expression.size() : nextPos + 1;
    }

    return results.empty() ? 0 : results.top();
}

int main()
{
    return 0;
}