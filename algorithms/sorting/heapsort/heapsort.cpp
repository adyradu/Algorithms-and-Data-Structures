#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

// Class representing a mean heap on integer values.
//
class MinHeapInt
{
public:

    // Default constructor
    //
    MinHeapInt()
    {}

    // It constructs a heap from an array.
    // It copies first the array into the heap's container
    // and then it calls progessively bubbleDown from the end
    // of the container to the beginning of the container.
    //
    MinHeapInt(vector<int> a)
        :
        container(vector<int>(a.size()))
    {
        for (int i = 0; i < a.size(); ++i) {
            container[i] = a[i];
        }

        for (int i = container.size() - 1; i >= 0; --i) {
            bubbleDown(i);
        }
    }

    // It sorts the array throgh a heap data structure.
    // It constructs a heap and then repopulates the array
    // by getting the minimum from the heap.
    //
    static void heapsort(vector<int>& a) {
        MinHeapInt minHeap(a);

        for (int i = 0; i < a.size(); ++i) {
            a[i] = minHeap.getMin();
            minHeap.deleteMin();
        }
    }

    // Inserts a new value into the heap.
    //
    void insert(int val);

    // Returns the minimum value from the heap.
    //
    int getMin() const;

    // Deletes the minimum value from the heap.
    //
    void deleteMin();

    // Returns whether the container is a heap or not.
    //
    bool isHeap() const;

private:

    // Returns the parent position.
    // This curPos * 2.
    //
    int getParentPos(int curPos) const
    {
        if (curPos == 0) {
            return -1;
        }

        return curPos / 2;
    }

    // Gets the position of the the child with the minimum
    // value. It can be either curPos * 2 or curPos * 2 + 1.
    //
    int getMinChildPos(int curPos) const
    {
        int leftChildPos = curPos * 2;
        
        if (leftChildPos >= container.size()) {
            return -1;
        }

        int rightChildPos = leftChildPos + 1;

        if (rightChildPos == container.size()) {
            return leftChildPos;
        }

        return container[leftChildPos] < container[rightChildPos] ?
            leftChildPos : rightChildPos;
    }

    // Given a position curPos it places the element at curPos
    // in the heap so that it satifies the heap properties.
    // The assumption is that all elements between curPos and
    // and the end of the container represent a valid heap.
    //
    void bubbleDown(int curPos);

private:
    vector<int> container;
};

// Inserts a new value into the heap.
//
void
MinHeapInt::insert(int val)
{
    container.push_back(val);

    int curPos = container.size() - 1;
    int parentPos = getParentPos(curPos);

    // Bubble up
    //
    while (curPos > 0 && container[parentPos] > container[curPos])
    {
        swap(container[curPos], container[parentPos]);
        curPos = parentPos;
        parentPos = getParentPos(curPos);
    }
}

// Returns the minimum value from the heap.
//
int
MinHeapInt::getMin() const
{
    if (container.size() == 0) {
        throw new exception("Heap is empty!");
    }

    return container[0];
}

// Given a position curPos it places the element at curPos
// in the heap so that it satifies the heap properties.
// The assumption is that all elements between curPos and
// and the end of the container represent a valid heap.
//
void
MinHeapInt::bubbleDown(int curPos)
{
    int minChildPos = getMinChildPos(curPos);

    // Bubble down
    //
    while(minChildPos >= 0 && container[curPos] > container[minChildPos]) {
        swap(container[curPos], container[minChildPos]);
        curPos = minChildPos;
        minChildPos = getMinChildPos(curPos);
    }    
}

// Deletes the minimum value from the heap.
// 
void MinHeapInt::deleteMin()
{
    if (container.size() == 0) {
        throw new exception("Heap is empty!");
    }

    swap(container[0], container[container.size() - 1]);
    container.pop_back();

    bubbleDown(0);
}

// Returns whether the container is a heap or not.
// 
bool
MinHeapInt::isHeap() const
{
    int n = container.size() / 2;
    for (int i = 0; i < n; ++i) {
        int leftChildPos = i * 2;
        int rightChildPos = leftChildPos + 1;
        if ((leftChildPos < container.size() && container[leftChildPos] < container[i]) ||
        (rightChildPos < container.size() && container[rightChildPos] < container[i])) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    MinHeapInt minHeap;

    minHeap.insert(3);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(5);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(8);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(6);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(0);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(21);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;

    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();

    minHeap.insert(1);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(1);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(0);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.insert(0);
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;

    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();
    cout<<minHeap.getMin()<<" "<<minHeap.isHeap()<<endl;
    minHeap.deleteMin();

    vector<int> a = {10, 8, 9, 6, 7, 0, 2, 1, 3, 5, 4};
    MinHeapInt::heapsort(a);

    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}