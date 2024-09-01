int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int prev = 0; //ǰһ��λ��
    int cur = 1;  //��һ��λ��
    int src = 0;  //ָ������
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