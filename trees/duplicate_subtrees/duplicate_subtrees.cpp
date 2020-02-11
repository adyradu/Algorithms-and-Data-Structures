// Find all duplicate subtrees in a binary tree.
// Print the root of subtrees only once
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

struct BTNode
{
    BTNode(int _val)
        :
        val(_val),
        left(nullptr),
        right(nullptr)
        {}

    int val;
    BTNode* left;
    BTNode* right;
};

string serialize(BTNode* root, unordered_map<string, int>& dups, vector<BTNode*>& result)
{
    if (!root) {
        return ".";
    }

    string str = to_string(root->val) + "," + serialize(root->left, dups, result) + "," +
        serialize(root->right, dups, result);

    unordered_map<string, int>::iterator got =
        dups.find(str);
    
    if (got == dups.end()) {
        dups.insert(pair<string, int>(str, 1));
    }
    else if (got->second == 1) {
        result.push_back(root);
        got->second += 1;
    }

    return str;
}

void getDuplicates(BTNode* root, vector<BTNode*>& result)
{
    unordered_map<string, int> dups;
    serialize(root, dups, result);   
}

int main(void) 
{
    BTNode* node1 = new BTNode(1);
    BTNode* node2 = new BTNode(2);
    BTNode* node3 = new BTNode(3);
    BTNode* node4 = new BTNode(4);
    BTNode* node5 = new BTNode(2);
    BTNode* node6 = new BTNode(4);
    BTNode* node7 = new BTNode(4);

    node1->left = node2; node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;
    node5->left = node7;

    vector<BTNode*> nodes;

    getDuplicates(node1, nodes);

    for(BTNode* node : nodes) {
        cout<<node->val<<" "; 
    }

    cout<<endl;

    return 0;
}