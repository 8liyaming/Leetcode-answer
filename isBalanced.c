/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~常考，与题目：另一棵树的子树类似~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 //***********************方法1：前序，复杂度：最好为O(N)，最坏为O(N^2)************************//
int TreeDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);

    return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
} 

bool isBalanced(struct TreeNode* root)
{
    //当前树判断
    if(root == NULL)
    {
        return true;
    }

    int gap = TreeDepth(root->left)-TreeDepth(root->right);
    if(abs(gap) > 1)
    {
        return false;
    }

    //判断左右子树，注意是所有的左右子树，所以要递归
    return isBalanced(root->left) && isBalanced(root->right);
}

//***********************方法2：后序，复杂度：最坏为O(N)  不用上面的函数，判断的时候同时返回高度***********************//
bool _isBalanced(struct TreeNode* root, int* pDepth)
{
    if (root == NULL)
    {
        *pDepth = 0;
        return true;
    }
    else
    {
        int leftDepth = 0;
        if (_isBalanced(root->left, &leftDepth) == false)
        {
            return false;
        }

        int rightDepth = 0;
        if (_isBalanced(root->right, &rightDepth) == false)
        {
            return false;
        }

        //走到此处说明左右子树都满足，再判断当前树
        if (abs(leftDepth - rightDepth) > 1)
        {
            return false;
        }
        else
        {
            *pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;  //真的时候返回高度，错误时候返回高度无意义
            return true;
        }
    }
}

bool isBalanced(struct TreeNode* root)
{
    int depth = 0;
    return _isBalanced(root, &depth);
}