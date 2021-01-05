#include<iostream>
#include<string>
#include<numeric>

using namespace std;

/// <summary>
/// Convert a spreadsheet encoding (A, B, ..., Z, AA, AB, ..., AAA)
/// into the corresponding integer. A corresponds to 1.
/// </summary>
/// <param name="col"></param>
/// <returns></returns>
int SSDecodeColID(const string& col)
{
	return accumulate(col.begin(), col.end(), 0, [](int result, char c)
	{
		return result * 26 + c - 'A' + 1;
	});
}

int main()
{
	cout << SSDecodeColID("ZZZ") << endl;
	return 0;
}