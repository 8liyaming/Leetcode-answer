/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void AdjustDown(int* a, int n, int root)  //���µ����㷨��ǰ�᣺������������С�ѻ��ߴ��(�ر���Ҫ��)
{
    int parent = root;
    int child = parent * 2 + 1;  //���跨���������Һ�����С���Ǹ�������

    while (child < n)  //���ӽڵ�λ�ó����ܵ����λ��ʱ�������ٽ���
    {
        //�ҳ����Һ�����С����һ��
        //ע�⣺���汣֤��child����Խ�磬��child+1���ܻ�Խ��(û���Һ��ӣ�С�ľ�������)���������油���ˡ�child+1 < n��������
        if (child + 1 < n && a[child + 1] > a[child])  //child+1����ʾ�Һ���  //**********��С�Ѵ˴���Ϊ: <************//
        {
            ++child;  //����Һ��ӵ�ֵ�����ӵ�ֵС���������󣬸���Ϊ�Һ��������Һ�����С���Ǹ�
        }

        //������ӽڵ�ȸ��׽ڵ�С���򽻻����ڵ�
        if (a[child] > a[parent])    //**********��С�Ѵ˴���Ϊ: <************//
        {
            int tmp = a[child];
            a[child] = a[parent];
            a[parent] = tmp;
            //ѭ������
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize)
{
    *returnSize = k;  //leetcodeͳһ��ƣ�ֻҪ�������飬��Ҫ��һ������Ͳ�����ȡ��������Ĵ�С

    int* retArr = (int*)malloc(sizeof(int) * k);

    if (k == 0)
    {
        return retArr;
    }

    //��K�����Ĵ�ѣ��ȶѶ�С���滻�Ѷ�����
    for (int i = 0; i < k; ++i)
    {
        retArr[i] = arr[i];
    }
    for (int i = (k - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(retArr, k, i);
    }

    for (int j = k; j < arrSize; ++j)
    {
        if (arr[j] < retArr[0])
        {
            retArr[0] = arr[j];  //��ʱ�����ѾͲ�һ���Ǵ�ѣ����������ӶѶ���ԭ���Ĵ�ѣ��ʿ����µ����㷨
            AdjustDown(retArr, k, 0);
        }
    }

    return retArr;
}
