// https://leetcode.com/problems/ipo/
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Project
{
    Project(int _profit,
            int _capital)
        :
        profit(_profit),
        capital(_capital)
    {}

    int profit;
    int capital;
};

bool projectsArrayComp(const Project& p1, const Project& p2)
{
    return p1.capital < p2.capital;
}

bool heapComp(const Project& p1, const Project& p2)
{
    return p1.profit < p2.profit;
}

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    vector<Project> heap;
    vector<Project> projects;
    int n = Profits.size();
    int low = 0, high = n - 1;
    
    for (int i = 0; i < n; ++i) {
        projects.push_back(Project(Profits[i], Capital[i]));
    }
    
    sort(projects.begin(), projects.end(), projectsArrayComp);
    make_heap(heap.begin(), heap.end(), heapComp);
    
    do {
        int newLow;
        // Push all the projects that we can afford to start
        // in the heap.
        //
        for (newLow = low; newLow <= high; ++newLow) {
            if (W >= projects[newLow].capital) {
                heap.push_back(projects[newLow]);
                push_heap(heap.begin(), heap.end(), heapComp);
            }
            else {
                break;
            }
        }
        
        if (heap.empty()) {
            break;
        }
        
        // Get the next project with the largest profit
        // and remove it from the heap.
        //
        Project newProject = heap.front();
        
        pop_heap(heap.begin(), heap.end(), heapComp);
        heap.pop_back();
        
        low = newLow;
        W += newProject.profit;
        --k;
    } while (k > 0);
    
    return W;
}

int main(void)
{
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    cout<<findMaximizedCapital(k, w, profits, capital)<<endl;

    return 0;
}