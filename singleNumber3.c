/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    //����������������������������һ�ε������Ľ����
    int ret = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        ret ^= nums[i];
    }
    //�ҳ�ret�ĵ�mλΪ1��λ
    int m = 0;
    while (m < 32)
    {
        if (ret & (1u << m))  //ע�����ȼ�����Ҫ��1 << m��
            //��Ҫ��u,��Ϊ��32λϵͳ�У��з������������Ƶĵ�31λ��ʾ����λ�����Ƶ�λ�������������������λ��
        {
            break;
        }
        else
        {
            ++m;
        }
    }
    //����(���ÿ��µ�����ռ�)
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

    *returnSize = 2;  //��Ŀ���Ķ������

    return retArr;
}