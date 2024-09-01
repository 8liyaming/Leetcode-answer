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
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));  //开辟空间为最大数的位数加1

    int numi = numSize - 1;
    int reti = 0;
    int nextnum = 0;  //进位
    while (len--)
    {
        //处理数组元素个数小于整数k的位数情况
        int a = 0;
        if (numi >= 0)
        {
            a = num[numi];
            numi--;
        }

        int ret = a + k % 10 + nextnum;
        // numi--;  如果不处理上述特殊情况，numi会比len先减到0
        k /= 10;

        //判断是否两位相加需要进1
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

    //处理最后两位数相加后的进位问题
    if (nextnum == 1)
    {
        retArr[reti] = 1;
        reti++;
    }

    //逆置数组
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
