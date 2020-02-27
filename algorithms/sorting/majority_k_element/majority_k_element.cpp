// Find all numbers that appear more than n/k times
// in an array where n is the size of the array.
// Idea: (Boyer-Moore Algorithm). The idea is that for
// an x that appear more than n/k times in the array if we
// take x and take away another k - 1 elements x remains popular.
// http://www.cs.utexas.edu/users/misra/scannedPdf.dir/FindRepeatedElements.pdf
//
#include<iostream>
#include<vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums, int k) {
    int contSize = k - 1;
    vector<int> candidates(contSize);
    vector<int> count(contSize);
    vector<int> result;

    count.assign(contSize, 0);
    
    // See if the element is in the array.
    //
    for (int i = 0; i < nums.size(); ++i) {
        bool found = false;
        for (int j = 0; j < contSize; ++j) {
            if (nums[i] == candidates[j] && count[j] > 0) {
                count[j]++;
                found = true;
                break;
            }
        }
        
        bool added = false;
        
        // if not found, see if there is a free slot
        //
        if (!found) {
            for (int j = 0; j < contSize; ++j) {
                if (count[j] <= 0) {
                    candidates[j] = nums[i];
                    count[j] = 1;
                    added = true;
                    break;
                }
            }
        }
        else {
            continue;
        }
        
        
        // subtract 1 from each candidate count.
        //
        if (!added) {
            for (int j = 0; j < contSize; ++j) {
                count[j]--;
            }
        }
    }
    
    // Verify if the elements appear more the n/3 times
    // in the array.
    //
    for (int i = 0; i < contSize; ++i) {
        
        if (count[i] <= 0) {
            continue;
        }
        
        int cnt = 0;
        
        for (int j = 0; j < nums.size(); ++j) {
            if (candidates[i] == nums[j]) {
                cnt++;
            }
        }
        
        if (cnt > nums.size() / k) {
            result.push_back(candidates[i]);
        }
    }

    return result;
}

int main(void)
{
    vector<int> test1 = {1, 1, 2, 1, 2, 4, 3};
    vector<int> result1 = majorityElement(test1, 3);

    for (int i = 0; i < result1.size(); ++i) {
        cout<<result1[i]<<" ";
    }
    cout<<endl;

    vector<int> test2 = {1, 1, 2, 1, 2, 2, 3, 6};
    vector<int> result2 = majorityElement(test2, 4);

    for (int i = 0; i < result2.size(); ++i) {
        cout<<result2[i]<<" ";
    }

    cout<<endl;

    return 0;
}