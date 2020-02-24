// Rotate an array by k positions.
// Time complexity O(n), space complexity O(1) 
//
#include<iostream>
#include<vector>

using namespace std;

int nextPos(int currentPos, int arraySize, int k) {
    return (currentPos + k)  % arraySize;
}

int prevPos(int currentPos, int arraySize, int k) {
    int result = (currentPos - k) % arraySize;
    if (result < 0) {
        result = arraySize + result;
    }
    
    return result;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    
    if (n == 0 || k == 0) {
        return;
    }
    
    int noRot = 0;
    int currentPos = 0;
    int finalPos = 0;
    int aux = 0;
    int auxPos = 0;
    
    for (int i = 0; i < n && noRot < n; ++i) {
        
        if (nums[i] < 0) {
            continue;
        }
        
        currentPos = i;
        finalPos = nextPos(currentPos, n, k);  
        aux = nums[finalPos];
        auxPos = finalPos;
        nums[finalPos] = nums[currentPos];
        finalPos = currentPos;
        currentPos = prevPos(currentPos, n, k);
        noRot++;
        
        while (currentPos != auxPos && noRot < n) {
            nums[finalPos] = nums[currentPos];
            finalPos = currentPos;
            currentPos = prevPos(currentPos, n, k);
            noRot++;
        }

        if (noRot < n) {
            finalPos = nextPos(currentPos, n, k);
            nums[finalPos] = aux;
            noRot++;
        }
    }
}


int main(void)
{
    vector<int> nums = {1,2,3,4,5,6,7,8};

    rotate(nums, 4);

    for (int n : nums) {
        cout<<n<<" ";
    }

    cout<<endl;

    return 0;
}