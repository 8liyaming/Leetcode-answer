//非常经典的一道题 
class Solution {
public:
    int firstUniqChar(string s)
    {
        //使用映射的方式统计次数
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};