// Find the maximum number in a k
// roted sorted array of distinct values.
//
#include<iostream>
#include<vector>

using namespace std;

int find_max_aux(const vector<int>& nums, int low, int high)
{
    if (low == high) {
        return nums[low];
    }

    int mid = (low + high) / 2;

    if (nums[mid] < nums[high] &&
        nums[low] < nums[high]) {
        return find_max_aux(nums, mid + 1, high);
    }

    if (nums[mid] > nums[high]) {
        if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1])) {
            return nums[mid];
        }
        
        return find_max_aux(nums, mid + 1, high);
    }

    if (nums[mid] < nums[low]) {
        return find_max_aux(nums, low, mid - 1);
    }
    else {
        return nums[mid];
    }
}

int find_max(const vector<int>& nums)
{
    return find_max_aux(nums, 0, nums.size() - 1);
}

int main(void)
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout<<find_max(nums1)<<endl;

    vector<int> nums2 = {5, 1, 2, 3, 4};
    cout<<find_max(nums2)<<endl;

    vector<int> nums3 = {4, 5, 1, 2, 3};
    cout<<find_max(nums3)<<endl;

    vector<int> nums4 = {3, 4, 5, 1, 2};
    cout<<find_max(nums4)<<endl;

    vector<int> nums5 = {2, 3, 4, 5, 1};
    cout<<find_max(nums5)<<endl;

    vector<int> nums6 = {1, 2, 3, 4};
    cout<<find_max(nums6)<<endl;

    vector<int> nums7 = {4, 1, 2, 3};
    cout<<find_max(nums7)<<endl;

    vector<int> nums8 = {3, 4, 1, 2};
    cout<<find_max(nums8)<<endl;

    vector<int> nums9 = {2, 3, 4, 1};
    cout<<find_max(nums9)<<endl;

    vector<int> nums10 = {1};
    cout<<find_max(nums10)<<endl;

    vector<int> nums11 = {2, 1};
    cout<<find_max(nums11)<<endl;

    vector<int> nums12 = {1, 2, 3};
    cout<<find_max(nums12)<<endl;

    return 0;
}