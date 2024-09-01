/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* a, int n, int* returnSize)
{
    *returnSize = n;
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1; //+1的目的是保证最后一次gap为1，/3是经验值
        for (int i = 0; i < n - gap; ++i) // 多组并排
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