// Find the kth element in an array.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int>& a, int low, int high)
{
    int pivot = low + rand() % (high - low);
    swap(a[pivot], a[high]);
    pivot = low;

    for (int i = low ;i < high; ++i) {
        if (a[i] < a[high]) {
            swap(a[i], a[pivot]);
            ++pivot;
        }
    }

    swap(a[high], a[pivot]);

    return pivot;
}

int quickSelect(vector<int> a, int low, int high, int k)
{
    if (low == high) {
        return low;
    }

    int pivot = partition(a, low, high);

    if (k == pivot) {
        return a[k];
    }
    else if (k < pivot) {
        return quickSelect(a, low, pivot - 1, k);
    }
    else {
        return quickSelect(a, pivot + 1, high, k);
    }
}

int main(void)
{
    vector<int> a = {2, 1, 4, 5, 17, 8, 10, 11, 13};

    cout<<quickSelect(a, 0, a.size() - 1, a.size() / 2);

    return 0;
}