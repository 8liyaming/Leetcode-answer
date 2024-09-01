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
        //**************����1*****************//
        //����ת��ǰ��
        //struct TreeNode* tmp = root->left;
        //root->left = root->right;
        //root->right = tmp;

        //�ݹ龵��ת������
        //invertTree(root->left);
        //invertTree(root->right);

        //return root;

        //**************����2����������ֵ��*****************//
        struct TreeNode* right = root->right;  //�м��������Ȼ��������
        root->right = invertTree(root->left);  //��߷�ת�����ӵ��ұ�
        root->left = invertTree(right);  //�ұ߷�ת�����ӵ����

        return root;
    }
}