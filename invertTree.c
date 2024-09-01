/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        //**************方法1*****************//
        //镜像翻转当前树
        //struct TreeNode* tmp = root->left;
        //root->left = root->right;
        //root->right = tmp;

        //递归镜像翻转左右树
        //invertTree(root->left);
        //invertTree(root->right);

        //return root;

        //**************方法2（借助返回值）*****************//
        struct TreeNode* right = root->right;  //中间变量，不然被覆盖了
        root->right = invertTree(root->left);  //左边反转后链接到右边
        root->left = invertTree(right);  //右边反转后链接到左边

        return root;
    }
}