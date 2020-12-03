#include<iostream>
#include<vector>

/// <summary>
/// Given a pivot and an array, partition athe array so that elements less than
/// pivot come first, then elements equal to the pivot and then the elements greater
/// than pivot.
/// This solution first traverses the array to move all elements less than pivot first.
/// The second pass moves all elements greater than the pivot last.
/// </summary>
/// <param name="pivot_index"></param>
/// <param name="A"></param>
void dutch_flag_partition_two_passes(int pivot_index, std::vector<int>& A)
{
    int smaller = 0, curr = 0, pivot = A[pivot_index], larger = A.size() - 1;
    while (curr < A.size())
    {
        if (A[curr] < pivot)
        {
            std::swap(A[smaller++], A[curr]);
        }
        curr++;
    }

    curr = larger;

    while (curr >= 0)
    {
        if (A[curr] > pivot) {
            std::swap(A[larger--], A[curr]);
        }
        curr--;
    }

    return;
}

/// <summary>
/// This solution traverses the array only once.
/// If we partition the array in smaller, equal, uknown and larger, the algorithm
/// traverses the unkown elements and whenever encounters an element less than the pivot
/// it moves it in the smaller group.
/// If it encounters an element equal to the pivot, it advances the current index.
/// If it encounters an element larger than the pivot it moves the element towards the end.
/// </summary>
/// <param name="pivot_index"></param>
/// <param name="A"></param>
void dutch_flag_partition_one_pass(int pivot_index, std::vector<int>& A)
{
    int smaller = 0, equal = 0, pivot = A[pivot_index], larger = A.size();

    while (equal < larger)
    {
        if (A[equal] == pivot)
        {
            ++equal;
        }
        else if (A[equal] < pivot)
        {
            std::swap(A[smaller++], A[equal++]);
        }
        else
        {
            std::swap(A[--larger], A[equal]);
        }
    }
}

int main(void)
{
    std::vector<int> A = { 1, 2, 1, 3, 5, 0, 6, 2 };
    dutch_flag_partition_one_pass(3, A);

    for (auto i : A)
    {
        std::cout << i << " ";
    }

	return 0;
}