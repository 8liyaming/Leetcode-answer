/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~����������Ŀ����һ��������������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 //***********************����1��ǰ�򣬸��Ӷȣ����ΪO(N)���ΪO(N^2)************************//
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
    //��ǰ���ж�
    if(root == NULL)
    {
        return true;
    }

    int gap = TreeDepth(root->left)-TreeDepth(root->right);
    if(abs(gap) > 1)
    {
        return false;
    }

    //�ж�����������ע�������е���������������Ҫ�ݹ�
    return isBalanced(root->left) && isBalanced(root->right);
}

//***********************����2�����򣬸��Ӷȣ��ΪO(N)  ��������ĺ������жϵ�ʱ��ͬʱ���ظ߶�***********************//
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

        //�ߵ��˴�˵���������������㣬���жϵ�ǰ��
        if (abs(leftDepth - rightDepth) > 1)
        {
            return false;
        }
        else
        {
            *pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;  //���ʱ�򷵻ظ߶ȣ�����ʱ�򷵻ظ߶�������
            return true;
        }
    }
}

bool isBalanced(struct TreeNode* root)
{
    int depth = 0;
    return _isBalanced(root, &depth);
}