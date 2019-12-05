/**
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 * Note that the number of times an item is used is the number of calls to the
 * get and put functions for that item since it was inserted. This number is
 * set to zero when the item is removed.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct LNode 
{
    LNode ()
        :
        key(-1),
        value(-1),
        freq(0),
        next(nullptr),
        prev(nullptr)
        {}
    
    LNode (
        int _key,
        int _value,
        int _freq)
        :
        key(_key),
        value(_value),
        freq(_freq),
        next(nullptr),
        prev(nullptr)
        {}
    
    int key;
    int value;
    int freq;
    LNode* next;
    LNode* prev;
};

class LFUCache
{
public:

    LFUCache (int capacity) {
        head = nullptr;
        cap = capacity;
        cnt = 0;
    }

    ~LFUCache () {
        LNode* cur = head;
        LNode* prev = nullptr;

        while (cur) {
            prev = cur;
            cur = cur->next;
            delete prev;
        }

        head = nullptr;
        cap = 0;
        cnt = 0;
    }

    void increaseFreq (LNode* node) {
        node->freq++;

        LNode* suc = node->next;

        while (suc && suc->freq <= node->freq)
        {
            if (suc->next) {
                suc->next->prev = node;
            }
            node->next = suc->next;

            if (node->prev) {
                node->prev->next = suc;
            }
            suc->prev = node->prev;

            node->prev = suc;
            suc->next = node;

            if (node == head) {
                head = suc;
            }

            suc = node->next;
        }
    }

    int get (int key) {
        auto got = map.find(key);

        // If the key is not in the cache return -1.
        //
        if (got == map.end()) {
            return -1;
        }

        LNode* node = got->second;
        int result = node->value;

        // Bump the frequency.
        //
        increaseFreq(node);

        return result;
    }
    
    void put(int key, int value) {
        if (cap == 0) {
            return;
        }

        auto got = map.find(key);

        if (got != map.end()) {
            LNode* node = got->second;
            node->value = value;
            increaseFreq(node);

            return;
        }

        // If the cache is full, evict the least frequently used element.
        //
        if (cnt == cap) {
            LNode* oldHead = head;
            int oldKey = oldHead->key;

            if (head->next) {
                head->next->prev = nullptr;
            }

            map.erase(oldKey);

            head = head->next;
            delete oldHead;

            cnt--;
        }

        // Add the new element.
        //
        LNode* newNode = new LNode(key, value, 0);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;

        increaseFreq(newNode);

        map.insert(pair<int, LNode*>(key, newNode));

        cnt++;
    }

private:
    LNode* head;
    int cap;
    int cnt;
    unordered_map<int, LNode*> map;
};

int main(void)
{
    LFUCache* lfucache = new LFUCache(2);

    lfucache->put(1, 1);
    lfucache->put(2, 2);
    cout<<lfucache->get(1)<<endl;
    lfucache->put(3,3);
    cout<<lfucache->get(2)<<endl;
    cout<<lfucache->get(3)<<endl;
    lfucache->put(4, 4);
    cout<<lfucache->get(1)<<endl;
    cout<<lfucache->get(3)<<endl;
    cout<<lfucache->get(4)<<endl;

    return 0;
}