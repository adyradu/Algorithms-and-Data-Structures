#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void sortArray()
{
	int n = 8, numbers[] = { 3, 12, 4, 20, 21, 14, 12, 0 };
	sort(numbers, numbers + n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

void sortVectorInc()
{
	vector<int> numbers = { 3, 12, 4, 20, 21, 14, 12, 0 };

	sort(numbers.begin(), numbers.end());

	for (int n : numbers)
	{
		printf("%d ", n);
	}

	printf("\n");
}

void sortVectorDesc()
{
	vector<int> numbers = { 3, 12, 4, 20, 21, 14, 12, 0 };

	sort(numbers.begin(), numbers.end(), [](int a, int b)
	{ return a > b; });

	for (int n : numbers)
	{
		printf("%d ", n);
	}

	printf("\n");
}

struct Person
{
	int height;
	string name;

	bool operator <(const Person& other)
	{
		return height < other.height;
	}
};

void sortStruct()
{
	vector<Person> persons = { Person {3, "Jane"}, Person {12, "Alice"}, Person {4, "Andrew"}, Person {20, "Julie"} };

	sort(persons.begin(), persons.end());

	for (Person p : persons)
	{
		printf("(%s, %d) ", p.name.c_str(), p.height);
	}

	printf("\n");
}

int main()
{
	sortArray();
	sortVectorInc();
	sortVectorDesc();
	sortStruct();

	return 0;
}