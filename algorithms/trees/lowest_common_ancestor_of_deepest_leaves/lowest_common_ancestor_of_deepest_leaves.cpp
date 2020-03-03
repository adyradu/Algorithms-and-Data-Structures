// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
//
#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        :
        val(x),
        left(nullptr),
        right(nullptr)
    {}
};

int depth(TreeNode* root, TreeNode*& cand, int& maxDepth, int d) {
    if (!root->left && !root->right) {
        if (d > maxDepth) {
            maxDepth = d;
            cand = root;
        }
        
        return d;
    }
    
    int childDepth = d + 1;
    int depthLeft = !root->left ? d : depth(root->left, cand, maxDepth, childDepth);
    int depthRight = !root->right ? d : depth(root->right, cand, maxDepth, childDepth);
    
    if (depthLeft == maxDepth && depthRight == maxDepth) {
        cand = root;
    }

    int res = max(depthLeft, depthRight);
    
    return res;   
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    
    TreeNode* cand = root;
    int maxDepth = 0;
    
    depth(root, cand, maxDepth, 0);
    
    return cand;
}

int main(void)
{
    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);

    TreeNode* ca = lcaDeepestLeaves(root);

    cout<<ca->val<<endl;

    return 0;
}