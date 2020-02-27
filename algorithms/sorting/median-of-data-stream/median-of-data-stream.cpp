// Median is the middle value in an ordered integer list.
// If the size of the list is even, there is no middle value.
// So the median is the mean of the two middle value.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int compMinHeap(int a, int b)
{
    return a >= b;
}

int compMaxHeap(int a, int b)
{
    return a < b;
}

// Maintain two heaps. The first heap will hold the elements that are less
// than the median plus the median itself if the size of the stream is odd, and
// the second heap will hold all elements that are higher than the median.
// When adding a new number, check and adjust the sizes of the two heaps so
// that at any time the two heap are either equal in size or the first heap
// has an additional element.
// Extracting the median at any time is an O(1) operation. Since the median is
// either the front of the first heap or the average of both fronts.
//
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        make_heap(minheap.begin(), minheap.end(), compMinHeap);
        make_heap(maxheap.begin(), maxheap.end(), compMaxHeap);
    }
    
    void addNum(int num) {
        if (maxheap.size() == 0) {
            maxheap.push_back(num);
            push_heap(maxheap.begin(), maxheap.end(), compMaxHeap);
        }
        else if (maxheap.size() == minheap.size()) {
            if (num <= minheap.front()) {
                maxheap.push_back(num);
                push_heap(maxheap.begin(), maxheap.end(), compMaxHeap);
            }
            else {
                minheap.push_back(num);
                push_heap(minheap.begin(), minheap.end(), compMinHeap);
                int minhalf = minheap.front();
                pop_heap(minheap.begin(), minheap.end(), compMinHeap);
                minheap.pop_back();
                maxheap.push_back(minhalf);
                push_heap(maxheap.begin(), maxheap.end(), compMaxHeap);
            }
        }
        else if (maxheap.size() > minheap.size()) {
            if (num >= maxheap.front()) {
                minheap.push_back(num);
                push_heap(minheap.begin(), minheap.end(), compMinHeap);
            }
            else {
                maxheap.push_back(num);
                push_heap(maxheap.begin(), maxheap.end(), compMaxHeap);
                int maxhalf = maxheap.front();
                pop_heap(maxheap.begin(), maxheap.end(), compMaxHeap);
                maxheap.pop_back();
                minheap.push_back(maxhalf);
                push_heap(minheap.begin(), minheap.end(), compMinHeap);
            }
        }
    }
    
    double findMedian() {
        if (maxheap.size() > minheap.size()) {
            return maxheap.front();
        }
        
        int maxhalf = maxheap.front();
        int minhalf = minheap.front();
        
        return (minhalf + maxhalf) / 2.;
    }
 
private:
    vector<int> minheap;
    vector<int> maxheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(void)
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(4);
    cout<<obj->findMedian()<<endl;
    obj->addNum(1);
    cout<<obj->findMedian()<<endl;
    obj->addNum(6);
    cout<<obj->findMedian()<<endl;
    obj->addNum(0);
    cout<<obj->findMedian()<<endl;
    obj->addNum(7);

    return 0;
}