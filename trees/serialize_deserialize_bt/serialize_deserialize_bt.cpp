// Given a binary tree, seriaize it into a string and then
// deserialize back.
//
#include<iostream>
#include<string>

using namespace std;

// BTree node
//
struct BTNode
{
    BTNode()
        :
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

// Serialize into a pre-order traversal.
//
string serialize(BTNode* root)
{
    if (root == nullptr) {
        return ".";
    }

    return to_string(root->val) + "," + serialize(root->left) +
            "," + serialize(root->right); 
}

// Given a string return the substring from index pos
// till character 'c'
//
string take(string s, int pos, char c, int& newPos)
{
    string result;
    for (newPos = pos; newPos < s.size(); ++newPos) {
        if (s[newPos] == c) {
            ++newPos;
            return result;
        }
        result.push_back(s[newPos]);
    }

    return result;
}

// Given a string, return a binary tree.
//
BTNode* deserialize_helper(string s, int& pos)
{
    if (pos == s.size()) {
        return nullptr;
    }

    // Take the next value or null symbol ('.')
    //
    string cs = take(s, pos, ',', pos);
    if (cs == ".") {
        return nullptr;
    }

    BTNode* left = deserialize_helper(s, pos);
    BTNode* right = deserialize_helper(s, pos); 

    BTNode* res =  new BTNode(stoi(cs),
        left,
        right);

    return res;
}

BTNode* deserialize(string s)
{
    int initPos = 0;
    return deserialize_helper(s, initPos);
}

int main(void)
{
    BTNode* node1 = new BTNode(5, nullptr, nullptr);
    BTNode* node2 = new BTNode(3, nullptr, nullptr);
    BTNode* node3 = new BTNode(8, nullptr, nullptr);
    BTNode* node4 = new BTNode(7, nullptr, nullptr);
    BTNode* node5 = new BTNode(1, nullptr, nullptr);
    BTNode* node6 = new BTNode(4, nullptr, nullptr);

//       5
//   3       8
// 1   4   7
//
// Expected serialization: 5,3,1,.,.,4,.,.,8,7,.,.,.

    node1->left = node2;
    node1->right = node3;
    node2->left = node5;
    node2->right = node6;
    node3->left = node4;

    string s1 = serialize(node1);
    cout<<s1<<endl;
    BTNode* resNode = deserialize(s1);
    cout<<serialize(resNode)<<endl;

    return 0;
}