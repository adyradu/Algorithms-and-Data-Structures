// Construct a binary tree from preorder
// and pos order traversal
//
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :
        val(x),
        left(nullptr),
        right(nullptr) {}
};

TreeNode* constr(vector<int>& pre, int preLow, int preHigh, vector<int>& post, int postLow, int postHigh) {
    if (preLow > preHigh) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(pre[preLow]);
    
    if (preLow == preHigh) {
        return root;
    }
    
    int L  = 0;
    int pos = 0;
    int preNext = preLow + 1;
    for (int i = postLow; i <= postHigh; ++i) {
        if (post[i] == pre[preNext]) {
            pos = i;
        }
    }
    
    L = pos - postLow + 1;
    
    root->left = constr(pre, preNext, preLow + L, post, postLow, postLow + L - 1);
    root->right = constr(pre, preLow + L + 1, preHigh, post, postLow + L, postHigh - 1);
    
    return root;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return constr(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
}

int main()
{
    return 0;
}