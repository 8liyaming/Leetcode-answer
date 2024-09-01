/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    //结构相同都为空
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //结构不同
    if (p == NULL && q != NULL)
    {
        return false;
    }

    //结构不同
    if (p != NULL && q == NULL)
    {
        return false;
    }

    //值不同
    if (p->val != q->val) //等于时并不能判断为相同的树，还要看左右子树，所以考虑不等于情况
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}