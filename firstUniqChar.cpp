//�ǳ������һ���� 
class Solution {
public:
    int firstUniqChar(string s)
    {
        //ʹ��ӳ��ķ�ʽͳ�ƴ���
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