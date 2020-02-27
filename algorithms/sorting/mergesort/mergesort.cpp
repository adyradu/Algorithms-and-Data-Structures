#include<iostream>
#include<vector>

using namespace std;

// Merge two sorted arrays.
//
void mergeArray(vector<int>& a, int low, int mid, int high)
{
    vector<int> bufferLeft;
    vector<int> bufferRight;

    for (int i = low; i < mid; ++i) {
        bufferLeft.push_back(a[i]);
    }

    for (int i = mid; i < high; ++i) {
        bufferRight.push_back(a[i]);
    }

    int k = low, i = 0, j = 0;
    for (; i < bufferLeft.size() && j < bufferRight.size();) {
        if (bufferLeft[i] < bufferRight[j]) {
            a[k++] = bufferLeft[i++];
        }
        else {
            a[k++] = bufferRight[j++];
        }
    }

    while(i < bufferLeft.size()) { a[k++] = bufferLeft[i++]; }
    while(j < bufferRight.size()) { a[k++] = bufferRight[j++]; }
}

void mergeSortArray(vector<int>& a, int low, int high)
{
    if (high - low <= 1) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortArray(a, low, mid);
    mergeSortArray(a, mid, high);
    mergeArray(a, low, mid, high);
}

int main(void)
{
    vector<int> a = {3,4,1,5,6,7,10,21,14,40,-1,-35,5};

    mergeSortArray(a, 0, a.size());

    for (int i = 0; i < a.size(); i++) {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}