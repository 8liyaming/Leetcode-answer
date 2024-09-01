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
    //�ṹ��ͬ��Ϊ��
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //�ṹ��ͬ
    if (p == NULL && q != NULL)
    {
        return false;
    }

    //�ṹ��ͬ
    if (p != NULL && q == NULL)
    {
        return false;
    }

    //ֵ��ͬ
    if (p->val != q->val) //����ʱ�������ж�Ϊ��ͬ��������Ҫ���������������Կ��ǲ��������
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}