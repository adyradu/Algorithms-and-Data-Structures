#include "linked_list.h"

template<typename T>
void
LinkedList<T>::Insert(const T& newVal)
{
    ListNode<T>* newNode = new ListNode<T>();
    
    if (last == nullptr)
    {
        last = newNode;
        head = last;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

template<typename T>
T
LinkedList<T>::Head()
{
    if (head != nullptr)
    {
        return head->value;
    }
}

template<typename T>
T
LinkedList<T>::Last()
{
    if (last != nullptr)
    {
        return last->value;
    }
}
