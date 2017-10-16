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


bool isBalanced(BinaryTreeNode* root, int depth, int &maxDepth, int &minDepth)
{
    bool isBalancedBST = true;
    
    if (root == 0)
        return true;
    else if (root->left_ == 0 && root->right_ == 0)
    {
        if (depth > maxDepth)
            maxDepth = depth;
        
        if (depth < minDepth)
            minDepth = depth;
        
        if (maxDepth - minDepth > 1)
            return false;
        return true;
    }
    else
    {
        isBalancedBST = isBalanced(root->left_, ++depth, maxDepth, minDepth);
        if (isBalancedBST)
            isBalancedBST = isBalanced(root->right_, depth, maxDepth, minDepth);
    }
    return isBalancedBST;
}

int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(8);
    BinaryTreeNode* left = root->insertLeft(7);
    BinaryTreeNode* right = root->insertRight(10);
    BinaryTreeNode* furtherLeft = left->insertLeft(5);
    BinaryTreeNode* leftLeaf = furtherLeft->insertLeft(3);
    
    int initDepth = 0;
    int initMaxDepth = 0;
    int initMinDepth = 99999;
    cout << (isBalanced(root, initDepth, initMaxDepth, initMinDepth) ? "Tree is Balanced" : "Tree is Not Balanced") << endl;
    return 0;
}