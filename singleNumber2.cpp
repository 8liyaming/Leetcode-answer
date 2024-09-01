class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        //ͳ�Ƴ�32��λ��ÿ��λ�ϼ�����1���ֵĴ���(ÿ��λ1�ĸ���Ҫô��3n,Ҫô3n+1)
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
            //����Ϊ3n+1��λ����ֻ����һ�ε���Ϊ1��λ
            if (bitsArray[i] % 3 == 1)
            {
                num |= (1 << i);
            }
        }

        return num;
    }
};