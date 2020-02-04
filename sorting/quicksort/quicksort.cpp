#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int pivotArray(vector<int>& a, int first, int last)
{
    int p = rand() % (first - last) + first;
    swap(a[p], a[last]);

    int firstGreater = first;
    for(int i = first; i < last; ++i) {
        if (a[i] < a[last]) {
            swap(a[i], a[firstGreater++]);
        }
    }

    swap(a[last], a[firstGreater]);

    return firstGreater;
}

void quickSortArray(vector<int>& a, int first, int last)
{
    if (last - first <= 0) {
        return;
    }

    int p = pivotArray(a, first, last);
    quickSortArray(a, first, p - 1);
    quickSortArray(a, p + 1, last); 
}

int main(void)
{
    vector<int> a = {7,4,5,2,1,0,1};

    quickSortArray(a, 0, a.size() - 1);

    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}