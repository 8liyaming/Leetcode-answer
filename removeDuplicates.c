int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int prev = 0; //前一个位置
    int cur = 1;  //后一个位置
    int src = 0;  //指针索引
    while (cur < numsSize) {
        if (nums[prev] != nums[cur]) {
            nums[src] = nums[prev];
            prev++;
            cur++;
            src++;
        }
        else {
            prev++;
            cur++;
        }
    }
    nums[src] = nums[prev];
    src++;
    prev++;
    return src;
}