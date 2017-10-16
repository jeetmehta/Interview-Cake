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


void isBalanced(BinaryTreeNode* root, vector <int> &depths, int depth)
{
    bool isBalancedBST = true;
    
    if (root == 0)
        return;
    else if (root->left_ == 0 && root->right_ == 0)
    {
        depths.push_back(depth);
        return;
    }
    else
    {
        isBalanced(root->left_, depths, ++depth);
        
        isBalanced(root->right_, depths, depth);
    }
}

void print_vector(vector <int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(8);
    BinaryTreeNode* left = root->insertLeft(7);
    BinaryTreeNode* right = root->insertRight(10);
    BinaryTreeNode* furtherLeft = left->insertLeft(5);
    BinaryTreeNode* leftLeaf = furtherLeft->insertLeft(3);

    vector <int> depths;
    isBalanced(root, depths, 0);
    print_vector(depths);
    for (int i = 0; i < depths.size(); i++)
    {
        for (int j = 0; j < depths.size(); j++)
        {
            int difference = depths[j] - depths[i];
            if (difference > 1)
            {
                cout << "Tree is Not Balanced" << endl;
                return 0;
            }
        }
    }
    cout << "Tree is Balanced" << endl;
    return 0;
}