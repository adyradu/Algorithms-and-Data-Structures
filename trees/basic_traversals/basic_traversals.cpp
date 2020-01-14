#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    BinaryTreeNode(int _value)
        :
        left(nullptr),
        right(nullptr),
        value(_value)
    {}

    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int value;
};

void insertBST(BinaryTreeNode** bt, int el)
{
    BinaryTreeNode* newNode = new BinaryTreeNode(el);

    if (*bt == nullptr) {
        *bt = newNode;
    }
    else
    {
        BinaryTreeNode* cur = *bt;
        
        while (true)
        {
            if (el < cur->value) {

                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = newNode;
                    break;
                }
            }
            else {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = newNode;
                    break;
                } 
            }
        }
    }
}

void preorderRec(BinaryTreeNode* bt)
{
    if (!bt)
    {
        return;
    }

    cout<<bt->value<<endl;
    preorderRec(bt->left);
    preorderRec(bt->right);
}

void postorderRec(BinaryTreeNode* bt)
{
    if (!bt)
    {
        return;
    }

    postorderRec(bt->left);
    postorderRec(bt->right);
    cout<<bt->value<<endl;
}

void inorderRec(BinaryTreeNode* bt)
{
    if (!bt)
    {
        return;
    }

    inorderRec(bt->left);
    cout<<bt->value<<endl;
    inorderRec(bt->right);
}

int main(void)
{
    BinaryTreeNode* bt = nullptr;
    insertBST(&bt, 10);
    insertBST(&bt, 5);
    insertBST(&bt, 17);
    insertBST(&bt, 14);

    preorderRec(bt);
    postorderRec(bt);
    inorderRec(bt);

    return 0;
}