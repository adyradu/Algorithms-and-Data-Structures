#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

class MinHeapInt
{
public:
    MinHeapInt()
    {}

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

    void bubbleDown(int curPos);

private:
    vector<int> container;
};

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

int
MinHeapInt::getMin() const
{
    if (container.size() == 0) {
        throw new exception("Heap is empty!");
    }

    return container[0];
}

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

void MinHeapInt::deleteMin()
{
    if (container.size() == 0) {
        throw new exception("Heap is empty!");
    }

    swap(container[0], container[container.size() - 1]);
    container.pop_back();

    bubbleDown(0);
}

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