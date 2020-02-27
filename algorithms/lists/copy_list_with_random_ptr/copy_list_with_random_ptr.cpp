// Given a list with next pointer and a random pointer
// return a deep copy of the list.
// O(n) time, O(n) space
//
#include<iostream>
#include<unordered_map>

using namespace std;

// Definition for a Node.
//
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node (int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {
    Node* cur = head;
    Node* newHead = nullptr;
    Node* newCur = nullptr;
    Node* newPrev = nullptr;
    unordered_map<Node*, Node*> nodeMap;
    
    if (!head) {
        return nullptr;
    }
    
    newHead = new Node(head->val);
    nodeMap.insert(pair<Node*, Node*>(head, newHead));
    cur = cur->next;
    newCur = newHead;
    newPrev = newCur;
    
    while (cur) {
        newCur = new Node(cur->val);
        
        nodeMap.insert(pair<Node*, Node*>(cur, newCur));
        
        newPrev->next = newCur;
        newPrev = newCur;
        cur = cur->next;
    }
    
    newCur = newHead;
    cur = head;
    
    while (newCur) {
        if (cur->random == nullptr) {
            newCur->random = nullptr;
        }
        else if (cur->random == cur) {
            newCur->random = newCur;
        }
        else {
            newCur->random = nodeMap[cur->random];
        }
        
        newCur = newCur->next;
        cur = cur->next;
    }
    
    return newHead;
}

int main(void)
{
    return 0;
}