/**
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * The cache is initialized with a positive capacity.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode;

struct CacheLine {
    CacheLine ()
        :
        key (-1),
        value (-1),
        ptr (nullptr)
        {}

    CacheLine (
        int _key,
        int _value,
        ListNode* _ptr)
        :
        key(_key),
        value(_value),
        ptr(_ptr)
        {}

    int key;
    int value;
    ListNode* ptr;
};

struct ListNode 
{
    ListNode()
        :
        key(-1),
        value(-1),
        next(nullptr),
        prev(nullptr)
        {}
    
    int key;
    int value;
    ListNode* next;
    ListNode* prev;
};
        
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;
        head = nullptr;
        last = nullptr;
    }

    ~LRUCache() {
        ListNode* cur = head;

        while (cur)
        {
            ListNode* prev = cur;
            cur = prev->next;
            delete prev;
        }

        head = nullptr;
        last = nullptr;
    }

    void moveLast(ListNode* ptr)
    {
        if (ptr->prev != nullptr) {
            ptr->prev->next = ptr->next;
        }
        
        if (ptr->next != nullptr) {
            ptr->next->prev = ptr->prev;
        }

        if (last != nullptr) {
            last->next = ptr;
        }
        ptr->prev = last;
        last = ptr;

        if (head == ptr) {
            head = ptr->next;
        }

        last->next = nullptr;
    }
    
    int get (int key) {

        // if not found in the cache, just return -1
        //
        auto got = map.find(key);

        if (got == map.end())
        {
            return -1;
        }

        CacheLine cacheLine = got->second;
        int result = cacheLine.value;

        ListNode* ptr = cacheLine.ptr;
        
        // Move the current element to the end of the list.
        //
        if (ptr == last) {
            return result;
        }

        moveLast(ptr);

        return result;
    }
    
    void put(int key, int value) {

        auto got = map.find(key);

        if (got != map.end()) {
            CacheLine cacheLine = got->second;

            map[key] = CacheLine(key, value, cacheLine.ptr);

            if (cacheLine.ptr != last) {
                moveLast(cacheLine.ptr);
            }

            return;
        }

        // If the cache is full, evict the
        // least recently used.
        //
        if (cnt == cap) {
            int firstKey = head->key;

            if (head->next) {
                head->next->prev = nullptr;
            }

            head = head->next;

            CacheLine cacheLine = map[firstKey];
            delete cacheLine.ptr;

            if (cap == 1) {
                head = nullptr;
                last = nullptr;
            }

            map.erase(firstKey);
        }

        // Insert the new cache entry at the end of the list.
        //
        ListNode* newNode = new ListNode();
        newNode->key = key;
        newNode->value = value;
        newNode->prev = last;

        if (last != nullptr) {
            last->next = newNode;
        }
        last = newNode;

        if (head == nullptr) {
            head = last;
        }

        CacheLine newCacheLine(key, value, last);
        map.insert(pair<int, CacheLine>(key, newCacheLine));

        if (cnt < cap) {
            cnt++;
        }
    }

private:
    int cap;
    int cnt;
    unordered_map<int, CacheLine> map;
    ListNode* head;
    ListNode* last;
};

int main(void)
{
    LRUCache c(2);

    c.put(2,1);
    c.put(2,2);
    cout<<c.get(2)<<endl;
    c.put(1,1);
    c.put(4,1);
    cout<<c.get(2)<<endl;   
    return 0;
}