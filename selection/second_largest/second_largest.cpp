// Select the second largest element in an unsorted array.
// The largest and the second largest elements are not duplicate.
// Find an algorithm using less than 2n-3 comparisons.
// The solution finds the second largest element in O(n+log(n))
// comparisons using a tournament tree.
//
#include <iostream>
#include <queue>

using namespace std;

struct BTNode
{
    BTNode(int _value)
        :
        value(_value),
        left(nullptr),
        right(nullptr)
    {}

    BTNode(int _value, BTNode* _left, BTNode* _right)
        :
        value(_value),
        left(_left),
        right(_right)
    {}

    int value;
    BTNode* left;
    BTNode* right;
};

// Create a tournament tree bottom up.
//
BTNode* createTournamentTree(const vector<int>& a)
{
    queue<BTNode*> q;

    for (int i = 0; i < a.size();++i)
    {
        q.push(new BTNode(a[i]));
    }

    while (q.size() > 1)
    {
        BTNode* cLeft = q.front(); q.pop();
        BTNode* cRight = nullptr;
        BTNode* winner = nullptr;

        if (!q.empty()) {
            cRight = q.front(); q.pop();

            int winnerValue = cLeft->value > cRight->value ? cLeft->value : cRight->value;
            winner = new BTNode(winnerValue, cLeft, cRight);
        }
        else
        {
            winner = new BTNode(cLeft->value, cLeft, nullptr);   
        }

        q.push(winner);
    }

    return q.empty() ? nullptr : q.front();
}

// It traverses the tournament tree as follows:
// Always follow the path of the winner and on the
// way peek the looser and adjust the second largest
// number. If the array has less than 1 element return
// INT_MIN.
//
int findSecondLargest(BTNode* root)
{
    BTNode* cur = root;

    if (!root) {
        return INT_MIN;
    }

    int maximum = root->value;
    int candidate = INT_MIN;

    while (cur) {
        BTNode* left = cur->left;
        BTNode* right = cur->right;
        BTNode* loser = nullptr;
        BTNode* winner = nullptr;

        if (!left || left->value != maximum) {
            loser = left;
            winner = right;
        }
        else {
            loser = right;
            winner = left;
        }

        if (loser && loser->value > candidate) {
            candidate = loser->value;
        }

        cur = winner;
    }

    return candidate;
}

int main(void)
{
    // Test1
    //
    vector<int> a1 = {2, 1, 3, 6, 7, 10, 9};
    BTNode* root1 = createTournamentTree(a1);
    cout<<findSecondLargest(root1)<<endl;

    // Test2
    //
    vector<int> a2 = {1};
    BTNode* root2 = createTournamentTree(a2);
    cout<<findSecondLargest(root2)<<endl;

    // Test3
    //
    vector<int> a3 = {};
    BTNode* root3 = createTournamentTree(a3);
    cout<<findSecondLargest(root3)<<endl;

    // Test4
    //
    vector<int> a4 = {6, 5, 4, 3, 2, 1};
    BTNode* root4 = createTournamentTree(a4);
    cout<<findSecondLargest(root4)<<endl;

    // Test5
    //
    vector<int> a5 = {1, 2, 3, 4, 5};
    BTNode* root5 = createTournamentTree(a5);
    cout<<findSecondLargest(root5)<<endl;

    // Test6
    //
    vector<int> a6 = {2, 1};
    BTNode* root6 = createTournamentTree(a6);
    cout<<findSecondLargest(root6)<<endl;

    // Test7
    //
    vector<int> a7 = {2, 1, 6, 7, 10, 12, 34, 44, 11, 9, 0, 4, 18, 24, 32, 17, 15, 13, 5};
    BTNode* root7 = createTournamentTree(a7);
    cout<<findSecondLargest(root7)<<endl;

    return 0;
}