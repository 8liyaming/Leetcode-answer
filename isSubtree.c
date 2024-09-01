/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)  //Letcode 100.�Ƿ�Ϊ��ͬ����
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

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
    {
        return false;
    }

    if (isSameTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}