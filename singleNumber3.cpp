class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //������֮��val����ֻ����һ�ε������������Ľ��
        int val = 0;
        for (auto e : nums)
        {
            val ^= e;
        }

        size_t i = 0;
        for (i = 0; i < 32; i++)
        {
            if (val & (1 << i))
            {
                break;
            }
        }

        int num1 = 0;
        int num2 = 0;
        for (auto e : nums)
        {
            if (e & (1 << i))
            {
                num1 ^= e;
            }
            else
            {
                num2 ^= e;
            }
        }

        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);

        return v;
    }
};