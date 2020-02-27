// Find all elements that appear more than
// n / 2 times in an array. The array size is
// n.
//
#include<iostream>
#include<vector>

using namespace std;

int findMajorityElement(vector<int> nums)
{
    int current_sum = 1;
    int candidate = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (current_sum == 0) {
            candidate = nums[i];
        }

        current_sum += (nums[i] == candidate) ? 1 : (-1);
    }

    // Check if the candidate appear more than n/2 times in
    // the array.
    //
    int times = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (candidate == nums[i]) {
            times++;
        }
    }

    if (times > nums.size() / 2) {
        return candidate;
    }

    return -1;
}

int main(void)
{
    vector<int> test1 = {1, 2, 1, 2, 1};
    vector<int> test2 = {2, 2, 1, 1};
    vector<int> test3 = {1, 2, 3};

    cout<<findMajorityElement(test1)<<endl;
    cout<<findMajorityElement(test2)<<endl;
    cout<<findMajorityElement(test3)<<endl;

    return 0;
}