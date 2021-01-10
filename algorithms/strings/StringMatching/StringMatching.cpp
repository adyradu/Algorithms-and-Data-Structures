#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Returns the index of the first character of the substring if found, -1
/// otherwise.
/// </summary>
/// <param name="t">The text to search to.</param>
/// <param name="s">The substring.</param>
/// <returns></returns>
int RabinKarp(const string& t, const string& s) {
    if (size(s) > size(t))
    {
        return -1;
    }

    const int kBase = 26;

    // t_hash - rolling hash of the candidate substring in t.
    // s_hash - rolling hash of substring s.
    //
    int t_hash = 0, s_hash = 0;
    // kBase ^ (|s| - 1) used to update the rolling hash of the candidate
    // substring.
    //
    int power_s = 1;

    // Calculate rolling hash of s and the initial candidate 
    // substring in t.
    //
    for (int i = 0; i < size(s); ++i)
    {
        power_s = i ? power_s * kBase : 1;
        s_hash = s_hash * kBase + s[i];
        t_hash = t_hash * kBase + t[i];
    }

    // Iterate through t and compute each time the
    // hash of the candidate substring as a sliding window.
    //
    for (int i = size(s); i < size(t); ++i)
    {
        // If the hashes match, compare the strings as well because
        // of potential hash collisions. If there are hash collisions,
        // two unrelated strings can have the same hash.
        //
        if (t_hash == s_hash && !t.compare(i - size(s), size(s), s))
        {
            return i - size(s);
        }

        t_hash -= t[i - size(s)] * power_s;
        t_hash = t_hash * kBase + t[i];
    }

    if (t_hash == s_hash && !t.compare(size(t) - size(s), size(s), s))
    {
        return size(t) - size(s);
    }

    return -1;
}

int main()
{
    cout << RabinKarp("cbabcde", "abc") << endl;
    return 0;
}