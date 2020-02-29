// Given the root of a binary tree, find the maximum value V for which there 
// exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
//
#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode {

    TreeNode(int x)
        :
        val(x),
        left(nullptr),
        right(nullptr)
    {}

    int val;
    TreeNode *left;
    TreeNode *right;
};

void maxAncestorDiffHelper(TreeNode* root, int cMin, int cMax, int& cand) {
    if (!root) {
        return;
    }
    
    cMin = min(root->val, cMin);
    cMax = max(root->val, cMax);
    
    int cDif = cMax - cMin;
    
    if (cDif > cand) {
        cand = cDif;
    }
    
    maxAncestorDiffHelper(root->left, cMin, cMax, cand);
    maxAncestorDiffHelper(root->right, cMin, cMax, cand);
}

int maxAncestorHelper(TreeNode* root) {
    int cand = INT_MIN;
    int cMin = INT_MAX;
    int cMax = INT_MIN;
    maxAncestorDiffHelper(root, cMin, cMax, cand);
    
    return cand;
}

int main(void)
{
    TreeNode* node1 = new TreeNode(4);

    cout<<maxAncestorHelper(node1)<<endl;;

    return 0;
}