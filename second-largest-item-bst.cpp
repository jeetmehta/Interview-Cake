#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode * insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode * insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

int getLargestValue(BinaryTreeNode *root)
{
    if (root == 0)
        return 0;

    BinaryTreeNode* temp = root;

    while (temp->right_ != 0)
    {
        temp = temp->right_;
    }

    return temp->value_;
}

int getSecondLargestValue(BinaryTreeNode* root)
{
    if (root == 0)
        return 0;

    BinaryTreeNode* temp = root;
    BinaryTreeNode* behindTemp = temp;

    while (temp->right_ != 0)
    {
        behindTemp = temp;
        temp = temp->right_;
    }

    if (temp->left_ != 0)
        return getLargestValue(temp->left_);
    return behindTemp->value_;
}

int main()
{
    // Create example tree
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* left = root->insertLeft(3);
    BinaryTreeNode* right = root->insertRight(8);

    left->insertRight(4);
    left->insertLeft(1);
    right->insertLeft(7);

    BinaryTreeNode* middle = right->insertRight(12);
    BinaryTreeNode* last = middle->insertLeft(10);
    last->insertLeft(9);
    last->insertRight(11);

    cout << "Second Largest Value in BST: " << getSecondLargestValue(root) << endl;

    return 0;
}