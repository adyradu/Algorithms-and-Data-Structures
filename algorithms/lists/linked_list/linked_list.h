#pragma once

template<typename T>
class IList<T>
{
public:
    T Head() const = 0;
    T Last() const = 0;
    void Insert(const T& newVal) = 0;
};

template<typename T>
class LinkedList : public IList
{
public:
    LinkedList()
        :
        head(nullptr),
        last(nullptr)
    {}

    T Head() const override;
    T Last() const override;
    void Insert(const T& newVal) override;

private:

    template<typename U>
    struct ListNode
    {
        ListNode<U>* next;
        U value;
    }

    ListNode<T>* head;
    ListNode<T>* last; 
};