// Give a binary search tree which has two
// nodes swapped, recover the tree without
// changing its structure.
//
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {

    TreeNode(int _val)
        :
        val(_val),
        left(nullptr),
        right(nullptr)
        {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* minNode(TreeNode* a, TreeNode* b)
{
    if (!b || a->val < b->val) {
        return a;
    }
    
    return b;
}

void detectError(TreeNode* root, TreeNode*& maxSoFar, vector<TreeNode*>& errNodes)
{
    if (!root) {
        return;
    }

    detectError(root->left, maxSoFar, errNodes);

    if (maxSoFar && root->val < maxSoFar->val) {
        errNodes[0] = maxSoFar;
        errNodes[1] = minNode(root, errNodes[1]);
    }
    else {
        maxSoFar = root;
    }

    detectError(root->right, maxSoFar, errNodes);
}
    
void recoverTree(TreeNode* root) {
    TreeNode* maxNode = nullptr;
    vector<TreeNode*> errNodes = {nullptr, nullptr};
    
    if (!root) {
        return;
    }
    
    detectError(root, maxNode, errNodes);
    
    swap(errNodes[0]->val, errNodes[1]->val);
}

int main(void)
{
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(4);

    node1->left = node3;
    node1->right = node2;

    recoverTree(node1);

    return 0;
}