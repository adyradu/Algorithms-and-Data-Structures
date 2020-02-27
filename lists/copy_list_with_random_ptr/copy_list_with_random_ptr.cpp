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
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* newHead = nullptr;
        Node* newCur = nullptr;
        Node* newPrev = nullptr;
        unordered_map<Node*, Node*> nodeMap;
        
        while (cur) {
            newCur = new Node(cur->val);
            
            nodeMap.insert(pair<Node*, Node*>(cur, newCur));
            
            if (newPrev) {
                newPrev->next = newCur;
            }
            else {
                newHead = newCur;
            }
            
            newPrev = newCur;
            cur = cur->next;
        }
        
        newCur = newHead;
        cur = head;
        
        while (newCur && cur) {
            if (cur->random == nullptr) {
                newCur->random = nullptr;
            }
            else if (cur->random == cur) {
                newCur->random = cur;
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