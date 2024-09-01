/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }

    //µ±Ç°Ê÷±È½Ï
    if (root->left && root->val != root->left->val)
    {
        return false;
    }

    if (root->right && root->val != root->right->val)
    {
        return false;
    }

    //µÝ¹éÅÐ¶Ï×óÓÒ×ÓÊ÷
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}