class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        //统计出32个位，每个位合计起来1出现的次数(每个位1的个数要么是3n,要么3n+1)
        int bitsArray[32] = { 0 };
        for (auto val : nums)
        {
            for (size_t i = 0; i < 32; ++i)
            {
                if (val & (1 << i))
                {
                    bitsArray[i]++;
                }
            }
        }

        int num = 0;
        for (size_t i = 0; i < 32; i++)
        {
            //次数为3n+1的位就是只出现一次的数为1的位
            if (bitsArray[i] % 3 == 1)
            {
                num |= (1 << i);
            }
        }

        return num;
    }
};