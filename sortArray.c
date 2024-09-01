/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* a, int n, int* returnSize)
{
    *returnSize = n;
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1; //+1��Ŀ���Ǳ�֤���һ��gapΪ1��/3�Ǿ���ֵ
        for (int i = 0; i < n - gap; ++i) // ���鲢��
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
    return a;
}