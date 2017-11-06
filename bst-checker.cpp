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

void fillInOrder(BinaryTreeNode *root, vector <int> &values)
{
    if (root == nullptr)
        return;

    fillInOrder(root->left_, values);
    values.push_back(root->value_);
    fillInOrder(root->right_, values);
}

bool isValidBST(BinaryTreeNode* root)
{
    vector <int> bstValues;
    fillInOrder(root, bstValues);

    for (int i = 0; i < bstValues.size() - 1; i++)
    {
        if (bstValues[i] > bstValues[i + 1])
            return false;
    }
    return true;
}

int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(7);
    BinaryTreeNode* left = root->insertLeft(6);
    BinaryTreeNode* right = root->insertRight(10);
    left->insertRight(8);
    
    if (isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;

    return 0;
}