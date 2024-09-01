/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void AdjustDown(int* a, int n, int root)  //向下调整算法，前提：左右子树都是小堆或者大堆(特别重要！)
{
    int parent = root;
    int child = parent * 2 + 1;  //假设法：假设左右孩子中小的那个是左孩子

    while (child < n)  //孩子节点位置超出总的最大位置时即不用再交换
    {
        //找出左右孩子中小的那一个
        //注意：上面保证了child不会越界，但child+1可能会越界(没有右孩子，小的就是左孩子)，故在下面补上了“child+1 < n”的条件
        if (child + 1 < n && a[child + 1] > a[child])  //child+1即表示右孩子  //**********排小堆此处改为: <************//
        {
            ++child;  //如果右孩子的值比左孩子的值小，则假设错误，更正为右孩子是左右孩子中小的那个
        }

        //如果孩子节点比父亲节点小，则交换两节点
        if (a[child] > a[parent])    //**********排小堆此处改为: <************//
        {
            int tmp = a[child];
            a[child] = a[parent];
            a[parent] = tmp;
            //循环迭代
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
    *returnSize = k;  //leetcode统一设计，只要返回数组，就要配一个输出型参数获取返回数组的大小

    int* retArr = (int*)malloc(sizeof(int) * k);

    if (k == 0)
    {
        return retArr;
    }

    //建K个数的大堆，比堆顶小就替换堆顶的数
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
            retArr[0] = arr[j];  //此时整个堆就不一定是大堆，但是左右子堆都是原来的大堆，故可向下调整算法
            AdjustDown(retArr, k, 0);
        }
    }

    return retArr;
}
