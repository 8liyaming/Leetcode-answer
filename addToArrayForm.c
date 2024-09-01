/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
    int kSize = 0;
    int kNum = k;
    while (kNum)
    {
        kSize++;
        kNum /= 10;
    }
    int len = numSize > kSize ? numSize : kSize;
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));  //���ٿռ�Ϊ�������λ����1

    int numi = numSize - 1;
    int reti = 0;
    int nextnum = 0;  //��λ
    while (len--)
    {
        //��������Ԫ�ظ���С������k��λ�����
        int a = 0;
        if (numi >= 0)
        {
            a = num[numi];
            numi--;
        }

        int ret = a + k % 10 + nextnum;
        // numi--;  ����������������������numi���len�ȼ���0
        k /= 10;

        //�ж��Ƿ���λ�����Ҫ��1
        if (ret > 9)
        {
            ret -= 10;
            nextnum = 1;
        }
        else
        {
            nextnum = 0;
        }

        retArr[reti] = ret;
        reti++;
    }

    //���������λ����Ӻ�Ľ�λ����
    if (nextnum == 1)
    {
        retArr[reti] = 1;
        reti++;
    }

    //��������
    int left = 0;
    int right = reti - 1;
    while (left < right)
    {
        int tmp = retArr[left];
        retArr[left] = retArr[right];
        retArr[right] = tmp;
        left++;
        right--;
    }

    *returnSize = reti;
    return retArr;
}
