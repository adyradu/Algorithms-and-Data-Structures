// Merge two sorted lists in place.
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

// Merge two lists in place.
//
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* resPtr = nullptr;
        ListNode* resHead = nullptr;
        
        while(ptr1 && ptr2) {
            ListNode* nextPtr1 = ptr1->next;
            ListNode* nextPtr2 = ptr2->next;
            
            if (ptr1->val < ptr2->val) {
                if (!resPtr) {
                    resPtr = ptr1;
                    resHead = resPtr;
                }
                else {
                    resPtr->next = ptr1;
                    resPtr = ptr1;
                }
                ptr1 = nextPtr1;
            }
            else {
                if (!resPtr) {
                    resPtr = ptr2;
                    resHead = resPtr;
                }
                else {
                    resPtr->next = ptr2;
                    resPtr = ptr2;
                }
                
                ptr2 = nextPtr2;
            }
        }
        
        while (ptr1) {
            ListNode* nextPtr1 = ptr1->next;
            if (!resPtr) {
                resPtr = ptr1;
                resHead = resPtr;
            }
            else {
                resPtr->next = ptr1;
                resPtr = ptr1;
            }
            ptr1 = nextPtr1;
        }
        
        while (ptr2) {
            ListNode* nextPtr2 = ptr2->next;
            if (!resPtr) {
                resPtr = ptr2;
                resHead = resPtr;
            }
            else {
                resPtr->next = ptr2;
                resPtr = ptr2;
            }
            ptr2 = nextPtr2;
        }
        
        return resHead;
    }

int main(void)
{
    ListNode* l1 = new ListNode(1); l1->next = new ListNode(4); l1->next->next = new ListNode(6);
    ListNode* l2 = new ListNode(0); l2->next = new ListNode(9);

    ListNode* l = mergeTwoLists(l1, l2);

    ListNode* cur  = l;

    while(cur) {
        cout<<cur->val<<" ";
        cur = cur->next;
    }

    cout<<endl;

    return 0;
}