// Find the median of two sorted arrays.
// This implements a solution with O(log(n + m)) time.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// return whether n is even or not.
//
bool isEven(int n) 
{
    return n % 2 == 0;
}

// Find the median of an array of size 1 and a sorted array with even size. 
//
double oneEven(vector<int>& a, int aLow, int aHigh, vector<int>& b, int b_low, int b_high)
{
    int midB1 = b_low + (b_high - b_low) / 2;
    int midB2 = midB1 + 1;
    
    if (a[aLow] < b[midB1]) {
        return b[midB1];
    }
    
    if (a[aLow] >= b[midB1] &&
        a[aLow] <= b[midB2]) {
        return a[aLow];
    }
    
    return b[midB2];
}

// Find the median of an array of size 1 and a sorted array with odd size. 
//
double oneOdd(vector<int>& a, int aLow, int aHigh, vector<int>& b, int b_low, int b_high)
{
    int midB = b_low + (b_high - b_low) / 2;
    int midBLeft = midB - 1;
    int midBRight = midB + 1;
    
    if (a[aLow] <= b[midBLeft]) {
        return (static_cast<double>(b[midBLeft]) + static_cast<double>(b[midB])) / 2;
    }
    
    if (a[aLow] > b[midBLeft] &&
        a[aLow] <= b[midB]) {
        return (static_cast<double>(a[aLow]) + static_cast<double>(b[midB])) / 2;
    }
    
    if (a[aLow] > b[midB] &&
        a[aLow] <= b[midBRight]) {
        return (static_cast<double>(a[aLow]) + static_cast<double>(b[midB])) / 2;
    }
    
    return (static_cast<double>(b[midB]) + static_cast<double>(b[midBRight])) / 2;
}

double medFour(int a, int b, int c, int d)
{
    vector<int> array;
    array.push_back(a);
    array.push_back(b);
    array.push_back(c);
    array.push_back(d);
    
    sort(array.begin(), array.end());
    
    return ((double)array[1] + (double)array[2]) / 2;
}

double medThree(int a, int b, int c) {
    vector<int> array;
    array.push_back(a);
    array.push_back(b);
    array.push_back(c);
    
    sort(array.begin(), array.end());
    
    return array[1];
}

double twoEven(vector<int>& a, int a_low, int a_high, vector<int>& b, int b_low, int b_high)
{
    int bMed = b_low + (b_high - b_low) / 2 + 1;
    return medFour(b[bMed], b[bMed - 1], max(a[a_low], b[bMed - 2]), min(a[a_high], b[bMed + 1]));
}

double twoOdd(vector<int>& a, int a_low, int a_high, vector<int>& b, int b_low, int b_high)
{
    int bMed = b_low + (b_high - b_low) / 2;
    
    return medThree(b[bMed], max(a[a_low], b[bMed - 1]), min(a[a_high], b[bMed + 1]));
}

double findMedianHelper(vector<int>& a, int a_low, int a_high, vector<int>& b, int b_low, int b_high)
{
    // |a| = 1, |b| = 1
    //
    if (a_low == a_high &&
        b_low == b_high) {
        return ((double)a[a_low] + (double)b[b_low]) / 2;
    }
    // |a| = 1, |b| even
    //
    else if (a_low == a_high &&
            isEven(b_high - b_low + 1)) {
        return oneEven(a, a_low, a_high, b, b_low, b_high);
    }
    // |a| = 1, |b| odd
    //
    else if (a_low == a_high) {
        return oneOdd(a, a_low, a_high, b, b_low, b_high);
    }
    // |a| = 2, |b| 2
    //
    else if (a_high - a_low == 1 &&
            b_high - b_low == 1) {
        return medFour(a[a_low], a[a_high], b[b_low], b[b_high]);
    }
    // |a| = 2, |b| even
    //
    else if (a_high - a_low == 1 &&
            isEven(b_high - b_low + 1)) {
        return twoEven(a, a_low, a_high, b, b_low, b_high);
    }
    // |a| = 2, |b| odd
    //
    else if (a_high - a_low == 1) {
        return twoOdd(a, a_low, a_high, b, b_low, b_high);
    }
    
    int midA = a_low + (a_high - a_low) / 2;
    int midB = b_low + (b_high - b_low) / 2;
   
    if (a[midA] > b[midB]) {
        int aHighNew = midA + ((a_high - a_low) % 2 == 0 ? 0 : 1);
        int bLowNew = b_low + a_high - aHighNew;
        if (aHighNew - a_low < b_high - bLowNew) {
            return findMedianHelper(a, a_low, aHighNew, b, bLowNew, b_high);
        }
        else {
            return findMedianHelper(b, bLowNew, b_high, a, a_low, aHighNew);
        }
    }
    else {
        int aLowNew = midA;
        int bHighNew = b_high - midA + a_low;
        if (a_high - aLowNew < bHighNew - b_low) {
            return findMedianHelper(a, aLowNew, a_high, b, b_low, bHighNew);
        }
        else {
            return findMedianHelper(b, b_low, bHighNew, a, aLowNew, a_high);
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 && isEven(nums2.size())) {
            return ((double)nums2[nums2.size() / 2] + (double)nums2[nums2.size() / 2 - 1]) / 2;
    }
    else if (nums1.size() == 0) {
        return nums2[nums2.size() / 2];
    }               
    else if (nums2.size() == 0 && isEven(nums1.size())) {
            return ((double)nums1[nums1.size() / 2] + (double)nums1[nums1.size() / 2 - 1]) / 2;
    }
    else if (nums2.size() == 0) {
        return nums1[nums1.size() / 2];
    }
    
    if (nums1.size() <= nums2.size()) {
        return findMedianHelper(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1);
    }

    return findMedianHelper(nums2, 0, nums2.size() - 1, nums1, 0, nums1.size() - 1);
}

int main(void)
{
    vector<int> a1 = {2, 4, 7, 8};
    vector<int> a2 = {1,5, 6, 9};

    cout<<findMedianSortedArrays(a1, a2)<<endl;;

    return 0;
}