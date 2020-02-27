// Detect the cycle in a linked list and return where
// the cycle begins.
//
#include<iostream>

using namespace std;

struct ListNode {
    ListNode(int x)
        : 
        val(x),
        next(nullptr)
        {}
    
    int val;
    ListNode *next;
 };

ListNode* detectCycle(ListNode* head) {
    ListNode* faster = head;
    ListNode* slower = head;
    
    if (!head) {
        return nullptr;
    }
    
    do {
        slower = slower->next;
        
        if (faster->next) {
            faster = faster->next->next;
        }
        else {
            return nullptr;
        }
        
    } while (slower != nullptr && faster != nullptr && slower != faster);
    
    
    if (slower == nullptr || faster == nullptr) {
        return nullptr;
    }
    
    slower = head;
    
    while(slower != faster) {
        slower = slower->next;
        faster = faster->next;
    }
    
    return slower;
}

int main(void)
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2; node2->next = node3;
    node3->next = node4; node4->next = node5;
    node5->next = node3;
    
    ListNode* cycleStarts = detectCycle(node1);

    cout<<(cycleStarts != nullptr ? cycleStarts->val : -1)<<endl;

    return 0;
}