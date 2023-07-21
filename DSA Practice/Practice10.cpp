//valid bst

#include <iostream>
#include <climits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTHelper(TreeNode *root, long long minVal, long long maxVal)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->val <= minVal || root->val >= maxVal)
    {
        return false;
    }

    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    if (isValidBST(root))
    {
        std::cout << "The tree is a valid Binary Search Tree." << std::endl;
    }
    else
    {
        std::cout << "The tree is not a valid Binary Search Tree." << std::endl;
    }

    // Remember to deallocate the memory to avoid memory leaks (not shown in this example).

    return 0;
}