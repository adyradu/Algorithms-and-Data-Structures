// Determine whether two trees are symmetrical.
//
#include <iostream>

using namespace std;

struct BTNode
{
    BTNode(int _val)
        :
        val(_val),
        left(nullptr),
        right(nullptr)
    {}

    BTNode(int _val, BTNode* _left, BTNode* _right)
        :
        val(_val),
        left(_left),
        right(_right)
    {}

    int val;
    BTNode* left;
    BTNode* right;
};

bool isMirrorHelper(BTNode* root1, BTNode* root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 == nullptr) {
        return false;
    }
    else if (root2 == nullptr) {
        return false;
    }

    return root1->val == root2->val &&
        isMirrorHelper(root1->left, root2->right) &&
        isMirrorHelper(root1->right, root2->left);
}

bool isMirror(BTNode* root) {
    if (!root) {
        return true;
    }

    return isMirrorHelper(root->left, root->right);
}

int main(void)
{
    // Case 1:
    // nullptr
    //
    cout<<isMirror(nullptr)<<endl;

    // Case 2:
    //    1
    //  2   2
    BTNode* node1 = new BTNode(1);
    BTNode* node2 = new BTNode(2);
    BTNode* node3 = new BTNode(2);
    node1->left = node2; node1->right = node3;
    cout<<isMirror(node1)<<endl;

    // Case 2:
    //    1
    //  2   3
    BTNode* node4 = new BTNode(1);
    BTNode* node5 = new BTNode(2);
    BTNode* node6 = new BTNode(3);
    node4->left = node5; node4->right = node6;
    cout<<isMirror(node4)<<endl;
    
    return 0;
}