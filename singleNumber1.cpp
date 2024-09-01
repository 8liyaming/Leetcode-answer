class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int val = 0;
        for (auto e : nums)
        {
            val ^= e;
        }

        return val;
    }
};