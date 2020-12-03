#include<iostream>
#include<vector>

/// <summary>
/// Arrange the elements of an array so that all even elements come first.
/// Expected space complexity is O(1).
/// </summary>
/// <param name="v"></param>
void even_odd(std::vector<int>& v)
{
	int nextEven = 0, nextOdd = v.size() - 1;

	while (nextEven < nextOdd)
	{
		if (v[nextEven] % 2 == 0)
		{
			nextEven++;
		}
		else
		{
			std::swap(v[nextEven], v[nextOdd--]);
		}
	}
}

int main()
{
	std::vector<int> v = { 14, 1, 3, 2, 0, 7, 18, 2 };
	even_odd(v);

	for (auto i : v)
	{
		std::cout << i << " ";
	}

	return 0;
}