// Construct a perfectly balanced binary tree from a
// sorted list.
//
#include<iostream>

using namespace std;

struct ListNode
{
    ListNode(int _val)
        :
        val(_val),
        next(nullptr)
        {}

    int val;
    ListNode* next;
};

struct BTreeNode
{
    BTreeNode(int _val)
        :
        val(_val),
        left(nullptr),
        right(nullptr)
        {}
    
    int val;
    BTreeNode* left;
    BTreeNode* right;
};

BTreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    
    ListNode* prevSlow = nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    
    if (!prevSlow) {
        return new BTreeNode(slow->val);
    }
    
    prevSlow->next = nullptr;
    
    BTreeNode* mid = new BTreeNode(slow->val);
    
    BTreeNode* left = sortedListToBST(head);
    BTreeNode* right = sortedListToBST(slow->next);
    
    mid->left = left;
    mid->right = right;
    
    return mid;
}

int main(void)
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;

    BTreeNode* btNode = sortedListToBST(node1);

    cout<<btNode->val<<endl;

    return 0;
}