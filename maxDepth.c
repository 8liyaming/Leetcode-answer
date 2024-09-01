/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //������Ϊ����������ȵ����ֵ+1 
int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    //return maxDepth(root->left) > maxDepth(root->right) ?
    //maxDepth(root->left) + 1 : maxDepth(root->right) + 1;  //�����������ݹ����Σ�����Ż���

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}