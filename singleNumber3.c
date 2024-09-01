/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    //异或所有数（结果等于两个仅出现一次的数异或的结果）
    int ret = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        ret ^= nums[i];
    }
    //找出ret的第m位为1的位
    int m = 0;
    while (m < 32)
    {
        if (ret & (1u << m))  //注意优先级，需要（1 << m）
            //需要加u,因为在32位系统中，有符号整数二进制的第31位表示符号位，左移的位数不允许超过整数本身的位数
        {
            break;
        }
        else
        {
            ++m;
        }
    }
    //分离(不用开新的数组空间)
    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] & (1u << m))
        {
            x1 ^= nums[i];
        }
        else
        {
            x2 ^= nums[i];
        }
    }

    int* retArr = (int*)malloc(sizeof(int) * 2);
    retArr[0] = x1;
    retArr[1] = x2;

    *returnSize = 2;  //题目给的多余参数

    return retArr;
}