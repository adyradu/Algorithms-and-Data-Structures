// Recover a binary tree from a preorder traversal
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
//
#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct TreeNode
{
    TreeNode (int _val)
        :
        val(_val),
        left(nullptr),
        right(nullptr)
    {}

    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* recoverFromPreorder(string S) {
    stack<pair<TreeNode*, int>> st;
    int idx = 0;
    int cNum = 0;
    int cDepth = 0;
    TreeNode* root = nullptr;
    
    while (idx <= S.size()) {
        if (idx < S.size() && isdigit(S[idx])) {
            cNum = cNum * 10 + S[idx] - '0';
        }
        else {
            if (cNum > 0) {
                TreeNode* newNode = new TreeNode(cNum);
                bool found = false;
                
                while (!st.empty() && !found) {
                    auto p = st.top();
                    TreeNode* candP = p.first;
                    int candPDist = p.second;
                    
                    if (candPDist + 1 == cDepth) {
                        if (!candP->left) {
                            candP->left = newNode;
                        }
                        else {
                            candP->right = newNode;
                        }
                        
                        st.push(pair<TreeNode*, int>(newNode, cDepth));
                        found = true;
                    }
                    else {
                        st.pop();
                    }
                }
                
                if (!found) {
                    st.push(pair<TreeNode*, int>(newNode, 0));
                    root = newNode;
                }
                
                cNum = 0;
                cDepth = 1;
            }
            else {
                ++cDepth;
            }
        }
        
        ++idx;
    }
    
    return root;
}

int main()
{
    string s = "1-401--349---90--88";
    TreeNode* root = recoverFromPreorder(s);

    cout<<root->val<<endl;

    return 0;
}