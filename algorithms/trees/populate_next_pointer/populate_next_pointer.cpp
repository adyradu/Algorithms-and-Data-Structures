// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/
//
#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root) {
        return nullptr;
    }
    
    queue<pair<Node*, int>> q;
    q.push(pair<Node*, int>(root, 0));
    
    while (!q.empty())
    {
        auto p = q.front(); q.pop();
        Node* cNode = p.first;
        int cLevel = p.second;
        
        if (q.empty()) {
            cNode->next = nullptr;
        }
        else {            
            auto np = q.front();
            Node* nNode = np.first;
            int nLevel = np.second;

            if (cLevel == nLevel) {
                cNode->next = nNode;
            }
            else {
                cNode->next = nullptr;
            }
        }
        
        if (cNode->left) {
            q.push(pair<Node*, int>(cNode->left, cLevel + 1));
        }
        
        if (cNode->right) {
            q.push(pair<Node*, int>(cNode->right, cLevel + 1));
        }
    }
    
    return root;
}

int main(void)
{
    return 0;
}