// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool compare(ListNode* l1, ListNode* l2)
{
    return l1->val > l2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* first = nullptr;
        ListNode* last = nullptr;
        vector<ListNode*> heap;
        
        for (auto it : lists)
        {
            if (it)
            {
                heap.push_back(it);
            }
        }
        
        make_heap(heap.begin(), heap.end(), compare);
        
        while (!heap.empty()) {
            ListNode* curNode = heap.front();
            
            // Create a new node.
            //
            ListNode* newNode = new ListNode(curNode->val);
            if (first == nullptr) {
                first = newNode;
                last = first;
            }
            else {
                last->next = newNode;
                last = newNode;
            }
            
            // Remove the minimum value from the heap
            //
            pop_heap(heap.begin(), heap.end(), compare); heap.pop_back();
            
            // Insert the next value into the heap
            //
            if (curNode->next) {
                heap.push_back(curNode->next); push_heap(heap.begin(), heap.end(), compare);
            }
        }
        
        return first;
    }
};

int main(void)
{
    return 0;
}