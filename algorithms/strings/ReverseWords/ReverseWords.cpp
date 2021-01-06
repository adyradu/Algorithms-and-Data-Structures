#include<iostream>
#include<string>

using namespace std;

/// <summary>
/// Reverse all the words in a sentence.
/// For example Alice likes Bob -> Bob likes Alice
/// Solution:
/// First reverse the entire string. Then reverse all
/// words in the string.
/// Time complexity: O(n), no additional space.
/// </summary>
/// <param name="s"></param>
void ReverseWords(string* s) {
    reverse(s->begin(), s->end());
    std::string::iterator last = s->begin();

    for (auto it = s->begin(); it != s->end(); ++it)
    {
        if (*it != ' ')
        {
            continue;
        }

        reverse(last, it);
        last = it + 1;
    }

    reverse(last, s->end());
}

int main()
{
    string s = "Alice likes Bob";
    ReverseWords(&s);
    cout << s << endl;

	return 0;
}