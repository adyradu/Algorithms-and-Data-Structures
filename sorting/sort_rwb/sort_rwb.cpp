// Suppose an array A consists of n elements, each of which is
// red(r), white(w), blue(b). Using only the following operations
// sort the array so that all red come before all white and all white
// come before all blue.
// Inspect(A, i) - report the color of the ith element of the array.
// Swap(A, i, j) - swap the ith element of the array with the jth element.
//
#include<iostream>
#include<vector>

using namespace std;

vector<char> colors = {'r', 'w'};

void sortRWBArray(vector<char>& a)
{
    int initPos = 0;

    for (char c : colors) {
        while(a[initPos] == c) {
            ++initPos;
        }

        for (int i = initPos; i < a.size(); ++i) {
            if (a[i] == c) {
                swap(a[initPos], a[i]);
                ++initPos;
            }
        }
    }
}

int main(void)
{
    vector<char> a = {'w', 'w', 'b', 'w', 'r', 'r', 'b', 'w', 'r'};
    sortRWBArray(a);
    for (char c : a) {
        cout<<c<<" ";
    }
    cout<<endl;

    vector<char> a1 = {'b', 'w', 'b', 'r'};
    sortRWBArray(a1);
    for (char c : a1) {
        cout<<c<<" ";
    }
    cout<<endl;

    vector<char> a2 = {'b', 'w', 'r'};
    sortRWBArray(a2);
    for (char c : a2) {
        cout<<c<<" ";
    }
    cout<<endl;

    vector<char> a3 = {'r', 'w', 'b'};
    sortRWBArray(a3);
    for (char c : a3) {
        cout<<c<<" ";
    }
    cout<<endl;

    vector<char> a4 = {'b', 'r'};
    sortRWBArray(a4);
    for (char c : a4) {
        cout<<c<<" ";
    }
    cout<<endl;

    vector<char> a5 = {'r', 'r'};
    sortRWBArray(a5);
    for (char c : a5) {
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}