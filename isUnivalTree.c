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

    //��ǰ���Ƚ�
    if (root->left && root->val != root->left->val)
    {
        return false;
    }

    if (root->right && root->val != root->right->val)
    {
        return false;
    }

    //�ݹ��ж���������
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}