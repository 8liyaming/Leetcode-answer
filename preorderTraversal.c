/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + TreeSize(root->left) + TreeSize(root->right);

    }
}

void _preorderTraversal(struct TreeNode* root, int* array, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    array[(*pi)++] = root->val;  //放到自己的数组中
    _preorderTraversal(root->left, array, pi);
    _preorderTraversal(root->right, array, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* array = (int*)malloc(sizeof(int) * size);
    int i = 0;
    _preorderTraversal(root, array, &i);  //注意：需要传递i的地址，而不是传i的值，这样确保了在递归过程中对同一个下标i加加

    *returnSize = size;
    return array;
}